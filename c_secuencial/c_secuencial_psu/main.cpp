#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <string>
#include <sstream>

using namespace std;

struct promedio{
    std::string rut;
    int ranking;
    int nem;
    int matematica;
    int lenguaje;
    int ciencias;
    int historia;

};

void integrantes(){
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebastián Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier Gálvez González" << std::endl;
}   

float fpromedio(int nem, int ranking, int matematica, int lenguaje, int ciencia, int historia){
    return (nem + ranking + matematica + lenguaje + historia + ciencia)/6;
}

int aleatoreo(int inferior, int superior){
    return (rand() % (superior - (inferior + 1))) +inferior;
}

void main_profe() {
    srand((unsigned int) time(0));
    std::string pyc(";");

    std::ofstream archivoSalida("puntajes.csv");

    for (unsigned long rut = 14916641; rut <= 19932391; rut++) {
        int nem = aleatoreo(475, 750);
        int ranking = aleatoreo(475, 750);
        int matematica = aleatoreo(475, 750);
        int lenguaje = aleatoreo(475, 750);
        int ciencias = aleatoreo(475, 750);
        int historia = aleatoreo(475, 750);

        std::string linea;
        linea = std::to_string(rut) + pyc + std::to_string(nem) + pyc + std::to_string(ranking) + pyc + std::to_string(matematica) + pyc + std::to_string(lenguaje) + pyc + std::to_string(ciencias) + pyc + std::to_string(historia);

        archivoSalida << linea << std::endl;
    }
  
    archivoSalida.close();
    std::cout << std::endl << "Archivo puntajes.csv creado" << std::endl;
}

bool existe(){
    std::fstream archivo;
    std::string linea_existente;
    archivo.open("puntajes.csv");
    archivo >> linea_existente;
    if(!archivo.is_open()){
        archivo.close();
        return false;
    }
    else{
        archivo.close();
        return true;
    }
}

void generarprom(){
    std::ofstream archivoSalida("prompuntajes.csv");
    promedio prueba;
    ifstream  lectura; 
    lectura.open("puntajes.csv",ios::in);

    for(std::string linea; std::getline(lectura,linea); ){
        std::stringstream registro (linea);
        std::string dato;
        for(int columna = 0; std::getline(registro, dato, ';'); columna++){
            switch (columna){
            case 0:
                prueba.rut = dato;
            case 1:
                prueba.nem = std::stoi(dato);
            case 2:
                prueba.ranking = std::stoi(dato);
            case 3:
                prueba.matematica =std::stoi(dato);
            case 4:
                prueba.lenguaje =std::stoi(dato);
            case 5:
                prueba.historia =std::stoi(dato);
            case 6:
                prueba.ciencias=std::stoi(dato);
            break;
            }
        }
        float prompuntaje = fpromedio(prueba.nem, prueba.ranking, prueba.matematica, prueba.lenguaje, prueba.historia, prueba.ciencias);
        std::string lin;
        lin = prueba.rut + ";" + std::to_string(prompuntaje);
        archivoSalida << lin << std::endl;   
    }
    archivoSalida.close();
    std::cout << std::endl << "Archivo prompuntajes.csv creado" << std::endl;
    
}

int main(int argc, char** argv) {
    std::cout << "Taller 1: C++ con OpenMP" << std::endl;
    bool comprobacion;
    comprobacion = existe ();
    if(!comprobacion){
        main_profe();
    }
    generarprom();
    integrantes();
    return EXIT_SUCCESS;
    
}