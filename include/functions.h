#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <filesystem>
#include <map>
#include <iostream>

extern std::map<std::string, std::string> caminhoSensores;

std::string obterString(std::string, int);
void inicializarSensores(std::string, std::string);

int obterLinha(std::string, std::string);

float uso_memoria(float&);
float uso_CPU();
float temp_CPU();
float temp_GPU();

#endif