#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include <vector>
#include "transporte.hpp"
#include "passageiro.hpp"
#include "cidade.hpp"

class Viagem {
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    Viagem* proxima; 
    int horasEmTransito;
    bool emAndamento;
public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);
    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado();
    bool isEmAndamento();
};

#endif
