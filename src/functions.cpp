#include "../include/functions.h"
#include <fstream>

std::string uso_memoria(std::string &memTotal){
    std::string memDisponivel, memoriaTotal;
    memoriaTotal = obterString("/proc/meminfo", 1);

    memoriaTotal.erase(0, 16);
    
    memTotal = memoriaTotal;

    memDisponivel = obterString("/proc/meminfo", 2);
    memDisponivel.erase(0, 17);

    return memDisponivel;
}

std::string obterString(std::string caminho, int linha){
    std::string lixo, resultado;
    std::ifstream fin;
    fin.open(caminho);
    if(fin.is_open()){
        for(int i = 1; i < linha; i++){
            std::getline(fin, lixo);
        }
        std::getline(fin, resultado);
    }
    return resultado;
}