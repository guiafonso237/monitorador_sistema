#include "../include/functions.h"
#include <iostream>
int main(){
    std::string memTotal;
    std::string memDisponivel = uso_memoria(memTotal);

    std::cout << memTotal << std::endl << memDisponivel << std::endl;

}