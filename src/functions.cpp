#include "../include/functions.h"
#include "../include/files_class.h"


namespace fs = std::filesystem;

std::map<std::string, std::string> caminhoSensores;

std::stringstream ss;

float uso_memoria(float &memTotal){
    std::string lixo;
    float memoriaDisponivel;

    ss.str(obterString("/proc/meminfo", 1));
    
    ss >> lixo;
    ss >> memTotal;

    memTotal = memTotal/1000000;
    memTotal = std::round(memTotal* 100) / 100;

    ss.clear();

    ss.str(obterString("/proc/meminfo", 3));

    ss >> lixo;
    ss >> memoriaDisponivel;

    memoriaDisponivel =  memoriaDisponivel/1000000;

    ss.clear();
    
    memoriaDisponivel = std::round(memoriaDisponivel * 100) / 100;

    return memoriaDisponivel;
}

std::string obterString(std::string caminho, int linha){
    File arquivo;

    arquivo.setCaminho(caminho);
    arquivo.setLinha(linha);

    arquivo.abrirArquivo();

    std::string resultado = arquivo.obterString();

    arquivo.fecharArquivo();

    return resultado;
}

int obterLinha(std::string caminho, std::string chave){
    std::string lixo;
    std::ifstream fin;
    int linha = 0;

    fin.open(caminho);

    try{
        while(std::getline(fin, lixo)){
            if(lixo.find(chave) != std::string::npos){
                fin.close();

                return linha;
            }

            linha++;
        }
    }
    catch(int erro){
        return -1;
    }
    return -2;
}

void inicializarSensores(std::string tipoSensor, std::string chave) {
    const std::string pathBase = "/sys/class/hwmon/";

    try {
        for (const auto& entry : fs::directory_iterator(pathBase)) {
            if (!entry.is_directory()) continue;

            std::ifstream nameFile(entry.path().string() + "/name");
            std::string deviceName;
            
            if (nameFile >> deviceName && deviceName == chave) {
                std::string tempPath = entry.path().string() + "/temp1_input";
                
                if (fs::exists(tempPath)) {
                    caminhoSensores[tipoSensor] = tempPath;
                    return;
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Erro de busca: " << e.what() << std::endl;
    }
}

float temp_CPU(){
    std::ifstream fin(caminhoSensores["CPU"]);
    float temp;

    try{
        if(fin >> temp){
            temp /= 1000;
            temp = std::round(temp * 100) / 100;

            return temp;
        }else{
            throw -1;
        }
    }catch(int e){
        return -2;
    }

}

float temp_GPU(){
    std::ifstream fin(caminhoSensores["GPU"]);
    float temp;

    try{
        if(fin >> temp){
            temp /= 1000;
            temp = std::round(temp * 100) / 100;

            return temp;
        }else{
            throw -1;
        }
    }catch(int e){
        return -2;
    }
}