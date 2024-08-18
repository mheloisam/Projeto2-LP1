#include "controlador_de_transito.hpp"
#include <iostream>

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;
    for (auto& cidade : cidades) {
        if (cidade->getNome() == nomeOrigem) {
            origem = cidade;
        }
        if (cidade->getNome() == nomeDestino) {
            destino = cidade;
        }
    }
    if (origem && destino) {
        origem->adicionarDistancia(destino, distancia);
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    } else {
        std::cout << "Cidades nao encontradas.\n";
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual) {
    Cidade* local = nullptr;
    for (auto& cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
        }
    }
    if (local) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, local));
    } else {
        std::cout << "Cidade nao encontrada para o transporte.\n";
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* local = nullptr;
    for (auto& cidade : cidades) {
        if (cidade->getNome() == localAtual) {
            local = cidade;
        }
    }
    if (local) {
        passageiros.push_back(new Passageiro(nome, local));
    } else {
        std::cout << "Cidade nao encontrada para o passageiro.\n";
    }
}

void ControladorDeTransito::iniciarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros, std::string nomeOrigem, std::string nomeDestino) {
    Transporte* transporte = nullptr;
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;
    
    for (auto& t : transportes) {
        if (t->getNome() == nomeTransporte) {
            transporte = t;
        }
    }
    
    for (auto& c : cidades) {
        if (c->getNome() == nomeOrigem) {
            origem = c;
        }
        if (c->getNome() == nomeDestino) {
            destino = c;
        }
    }
    
    if (transporte && origem && destino) {
        std::vector<Passageiro*> passageirosViagem;
        for (auto& nome : nomesPassageiros) {
            for (auto& p : passageiros) {
                if (p->getNome() == nome) {
                    passageirosViagem.push_back(p);
                }
            }
        }
        Viagem* viagem = new Viagem(transporte, passageirosViagem, origem, destino);
        transporte->setLocalAtual(origem);
        viagens.push_back(viagem);
    } else {
        std::cout << "Transporte, origem ou destino nao encontrados.\n";
    }
}

void ControladorDeTransito::avancarHoras(int horas) {
    for (auto& viagem : viagens) {
        viagem->avancarHoras(horas);
    }
}

void ControladorDeTransito::relatarEstado() {
    for (auto& viagem : viagens) {
        viagem->relatarEstado();
    }
}
