#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;


void integrantes(){
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebastián Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier Gálvez González" << std::endl;
}   


int aleatoreo(int inferior, int superior){
    return (rand() % (superior - (inferior + 1))) +inferior;
}

int main(int argc, char** argv) {
    srand((unsigned int) time(0));
    std::string pyc(";");

    std::ofstream archivoSalida("puntajes.csv");

#pragma omp parallel 
    {

#pragma omp for
        for (unsigned long rut = 14916641; rut <= 19932391; rut++) {
            int nem = aleatoreo(475, 750);
            int ranking = aleatoreo(475, 750);
            int matematica = aleatoreo(475, 750);
            int lenguaje = aleatoreo(475, 750);
            int ciencias = aleatoreo(475, 750);
            int historia = aleatoreo(475, 750);

            std::string linea;
            linea = std::to_string(rut) + pyc + std::to_string(nem) + pyc + std::to_string(ranking) + pyc + std::to_string(matematica) + pyc + std::to_string(lenguaje) + pyc + std::to_string(ciencias) + pyc + std::to_string(historia);

#pragma omp critical
            archivoSalida << linea << std::endl;
        }
    }
    archivoSalida.close();
    std::cout << std::endl << "Archivo puntajes.csv creado" << std::endl;
}


