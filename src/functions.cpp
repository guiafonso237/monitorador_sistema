#include "../include/functions.h"
#include <fstream>
#include <cmath>

float uso_memoria(float &memTotal){
    std::string memDisponivel, memoriaTotal;
    
    memoriaTotal = obterString("/proc/meminfo", 1);
    memoriaTotal.erase(0,9);

    while(memoriaTotal[0] == ' '){
        memoriaTotal.erase(0,1);
    }

    size_t pos = memoriaTotal.find(' ');
    memoriaTotal = memoriaTotal.substr(0, pos);
    
    memTotal = stof(memoriaTotal)/1000000;
    memTotal = std::round(memTotal* 100) / 100;

    memDisponivel = obterString("/proc/meminfo", 3);
    memDisponivel.erase(0, 13);
    
    while(memDisponivel[0] == ' '){
        memDisponivel.erase(0,1);
    }

    pos = memDisponivel.find(' ');
    memDisponivel = memDisponivel.substr(0, pos);

    float memoriaDisponivel =  std::stof(memDisponivel)/1000000;

    return std::round(memoriaDisponivel * 100) / 100;
}

std::string obterString(std::string caminho, int linha){
    std::string lixo, resultado;
    std::ifstream fin;

    fin.open(caminho);

    try{
        if(!fin.is_open()){
            throw -1;
        }

        for(int i = 1; i < linha; i++){
            std::getline(fin, lixo);
        }

        std::getline(fin, resultado);
        fin.close();

        return resultado;
    }
    catch(int erro){
        return "";
    }
}

int obterLinha(std::string caminho, std::string chave){

}