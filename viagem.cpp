#include "viagem.hpp"
#include <iostream>

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino), horasEmTransito(0), emAndamento(true), proxima(nullptr) {}

void Viagem::iniciarViagem() {
    if (transporte->getLocalAtual() == origem) {
        emAndamento = true;
    } else {
        std::cout << "O transporte nao esta na cidade de origem.\n";
    }
}

void Viagem::avancarHoras(int horas) {
    if (emAndamento) {
        horasEmTransito += horas;
        
        int tempoTotal = transporte->calcularTempoTotal(origem, destino);
        
        if (tempoTotal < 0) {
            std::cout << "Distancia entre as cidades nao encontrada.\n";
            return;
        }

        std::cout << "Horas em transito: " << horasEmTransito << ", Tempo total necessario: " << tempoTotal << std::endl;

        if (horasEmTransito >= tempoTotal) {
            emAndamento = false;
            std::cout << "Viagem concluida!\n";
            for (auto& passageiro : passageiros) {
                passageiro->setLocalAtual(destino);
            }
            transporte->setLocalAtual(destino);
        }
    }
}

void Viagem::relatarEstado() {
    if (emAndamento) {
        std::cout << "Viagem em andamento de " << origem->getNome() << " para " << destino->getNome() << ". Horas em transito: " << horasEmTransito << std::endl;
    } else {
        std::cout << "Viagem concluida de " << origem->getNome() << " para " << destino->getNome() << ". Total de horas: " << horasEmTransito << std::endl;
    }
}

bool Viagem::isEmAndamento() {
    return emAndamento;
}
