#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

struct promedio{
    std::string rut;
    float ranking;
    float nem;
    float matematica;
    float lenguaje;
    float ciencias;
    float historia;

};

void integrantes(){ //Integrantes del grupo
    char a = 160;
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebasti"<<a<<"n Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier G"<<a<<"lvez González" << std::endl;
}   

float fpromedio(float nem, float ranking, float matematica, float lenguaje, float ciencia, float historia){
    return (nem + ranking + matematica + lenguaje + historia + ciencia)/6;
} //Funcion para obtener el promedio de los 6 puntajes dados

int aleatoreo(int inferior, int superior){
    return (rand() % (superior - (inferior + 1))) +inferior;
}

//Funcion donde genere ek archivo puntajes.csv
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
//Funcion para verificar si existe o no el archivo puntajes.csv
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

//Funcion que genera otro archivo propuntajes, 
//donde se obtiene los promedios de puntajes de cada
//leyendo desde el archivo puntajes.csv
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
                prueba.nem = std::stof(dato);
            case 2:
                prueba.ranking = std::stof(dato);
            case 3:
                prueba.matematica =std::stof(dato);
            case 4:
                prueba.lenguaje =std::stof(dato);
            case 5:
                prueba.historia =std::stof(dato);
            case 6:
                prueba.ciencias=std::stof(dato);
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

//Funcion main
int main(int argc, char** argv) {
    std::cout << "Taller 1: C++ secuencial" << std::endl;
    bool comprobacion;
    comprobacion = existe ();
    if(!comprobacion){
        main_profe();
    }
    generarprom();
    integrantes();
    return EXIT_SUCCESS;
    
}
