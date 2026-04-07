#include "../include/functions.h"
#include <fstream>

std::string uso_memoria(std::string &memTotal){
    std::ifstream fin;
    std::string memDisponivel, memoriaTotal;

    fin.open("/proc/meminfo");
    if(fin.is_open()){
        std::getline(fin, memoriaTotal);
        std::getline(fin, memDisponivel);
    }else{
        return "Não foi possível analisar mamória";
    }
    
    memTotal = memoriaTotal;
    return memDisponivel;
}