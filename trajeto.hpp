#ifndef TRAJETO_HPP
#define TRAJETO_HPP

#include "cidade.hpp"

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;
    char tipo; 
    int distancia;
public:
    Trajeto(Cidade* origem, Cidade* destino, char tipo, float distancia);
    Cidade* getOrigem();
    Cidade* getDestino();
    char getTipo();
    int getDistancia();
};

#endif
