#ifndef FILES_CLASS_H
#define FILES_CLASS_H

#include <string>
#include <fstream>

class File{
    private:
        std::ifstream fin;
        std::string caminho = "", chave = "";
        int linha;
    
    public:
        void setCaminho(std::string caminho);
        void setLinha(int linha);
        void setChave(std::string chave);

        std::string getCaminho();
        int getLinha();
        std::string getChave();

        std::string obterString();
        //int obterLinha();
        void abrirArquivo();
        void const fecharArquivo();
};

#endif