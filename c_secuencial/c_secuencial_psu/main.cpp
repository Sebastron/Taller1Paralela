#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
    std::cout << "Taller 1: C++, OpenMP y Dart" << std::endl;
    std::ofstream archivoSalida("prompuntajes.csv");
    for (unsigned long rut = 14916641; rut <= 19932391; rut++) {
        float nem = aleatoreo(475, 750);
        float ranking = aleatoreo(475, 750);
        float matematica = aleatoreo(475, 750);
        float lenguaje = aleatoreo(475, 750);
        float ciencia = aleatoreo(475, 750);
        float historia = aleatoreo(475, 750);
        float prompuntaje = (nem + ranking + matematica + lenguaje + ciencia + historia)/6;
        std::string linea;
        linea = std::to_string(rut) + ";" + std::to_string(prompuntaje);
        archivoSalida << linea << std::endl;
    }
    archivoSalida.close();

    integrantes();
    return EXIT_SUCCESS;
}
