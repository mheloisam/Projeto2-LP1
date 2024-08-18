#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include <string>
#include "cidade.hpp"

class Transporte {
private:
    std::string nome;
    char tipo; // 'A' para Aquático, 'T' para Terrestre
    int capacidade; // número de passageiros
    int velocidade; // km/h
    int distancia_entre_descansos; // em km
    int tempo_de_descanso; // em horas
    int tempo_de_descanso_atual;  // em horas
    Cidade* localAtual;
public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual);
    std::string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
    
    int calcularTempoTotal(Cidade* origem, Cidade* destino);
};

#endif
