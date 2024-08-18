#ifndef PASSAGEIRO_HPP
#define PASSAGEIRO_HPP

#include <string>
#include "cidade.hpp"

class Passageiro {
private:
    std::string nome;
    Cidade* localAtual;
public:
    Passageiro(std::string nome, Cidade* localAtual);
    std::string getNome();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};

#endif 
