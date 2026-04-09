#include "../include/functions.h"
#include <iostream>

int main(){
    float memTotal;
    float memDisponivel = uso_memoria(memTotal);

    std::cout << "Memoria Total: " << memTotal << std::endl << "Memoria Disponivel: " <<memDisponivel << std::endl;

}