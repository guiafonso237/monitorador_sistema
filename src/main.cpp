#include "../include/functions.h"

#include <iostream>
#include <cstdlib>
#include <thread> 
#include <chrono>

int main(){
    float memTotal;
    float memDisponivel = uso_memoria(memTotal);

    inicializarSensores("CPU", "k10temp");
    inicializarSensores("GPU", "amdgpu");


    while(true){
        system("clear");

        memDisponivel = uso_memoria(memTotal);

        std::cout << "Memoria Total: " << memTotal << " GB" << std::endl << "Memoria Disponivel: " << memDisponivel << " GB" << std::endl;
        std::cout << "Temperatura do Processador: " << temp_CPU() << " °C" << std::endl;
        std::cout << "Temperatura da Placa de Vídeo: " << temp_GPU() << " °C" << std::endl; 

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    

    return 0;
}