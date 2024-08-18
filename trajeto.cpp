#include "trajeto.hpp"

Trajeto::Trajeto(Cidade* origem, Cidade* destino, char tipo, float distancia)
    : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}

Cidade* Trajeto::getOrigem() {
    return origem;
}

Cidade* Trajeto::getDestino() {
    return destino;
}

char Trajeto::getTipo() {
    return tipo;
}

int Trajeto::getDistancia() {
    return distancia;
}
