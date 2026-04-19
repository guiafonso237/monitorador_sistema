#include "../include/files_class.h"

void File::setCaminho(std::string caminho){
    this->caminho = caminho;
}

void File::setLinha(int linha){
    this->linha = linha;
}

void File::setChave(std::string chave){
    this->chave = chave;
}

std::string File::getCaminho(){
    return this->caminho;
}

int File::getLinha(){
    return this->linha;
}

std::string File::getChave(){
    return this->chave;
}

void File::abrirArquivo(){
    this->fin.open(this->caminho);
    
}

void const File::fecharArquivo(){
    fin.close();
}

std::string File::obterString(){
    std::string lixo, resultado;

    try{
        if(!fin.is_open()){
            throw -1;
        }

        for(int i = 1; i < this->linha; i++){
            std::getline(fin, lixo);
        }

        std::getline(fin, resultado);

        return resultado;
    }
    catch(int erro){
        return "";
    }
}
