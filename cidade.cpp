#include "cidade.hpp"

Cidade::Cidade(std::string nome) : nome(nome) {}

std::string Cidade::getNome() {
    return nome;
}

void Cidade::adicionarDistancia(Cidade* destino, int distancia) {
    distancias.push_back(std::make_pair(destino, distancia));
}

int Cidade::obterDistanciaPara(Cidade* destino) {
    for (const auto& par : distancias) {
        if (par.first == destino) {
            return par.second;
        }
    }
    return -1;
}
