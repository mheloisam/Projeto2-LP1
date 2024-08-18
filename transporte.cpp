#include "transporte.hpp"

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual)
    : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade), distancia_entre_descansos(distancia_entre_descansos), tempo_de_descanso(tempo_de_descanso), tempo_de_descanso_atual(0), localAtual(localAtual) {}

std::string Transporte::getNome() {
    return nome;
}

char Transporte::getTipo() {
    return tipo;
}

int Transporte::getCapacidade() {
    return capacidade;
}

int Transporte::getVelocidade() {
    return velocidade;
}

int Transporte::getDistanciaEntreDescansos() {
    return distancia_entre_descansos;
}

int Transporte::getTempoDescanso() {
    return tempo_de_descanso;
}

int Transporte::getTempoDescansoAtual() {
    return tempo_de_descanso_atual;
}

Cidade* Transporte::getLocalAtual() {
    return localAtual;
}

void Transporte::setLocalAtual(Cidade* local) {
    localAtual = local;
}

int Transporte::calcularTempoTotal(Cidade* origem, Cidade* destino) {
    int distancia = origem->obterDistanciaPara(destino);
    
    if (distancia < 0) {
        return -1;
    }

    int tempoSemDescanso = distancia / velocidade;
    int numeroDeDescansos = distancia / distancia_entre_descansos;
    int tempoTotal = tempoSemDescanso + (numeroDeDescansos * tempo_de_descanso);
    
    return tempoTotal;
}
