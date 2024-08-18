#include <iostream>
#include "controlador_de_transito.hpp"

int main() {
    ControladorDeTransito controlador;
    int opcao;

    do {
        std::cout << "\nSistema Controlador de Viagens\n";
        std::cout << "1. Cadastrar Cidade\n";
        std::cout << "2. Cadastrar Trajeto\n";
        std::cout << "3. Cadastrar Transporte\n";
        std::cout << "4. Cadastrar Passageiro\n";
        std::cout << "5. Iniciar Viagem\n";
        std::cout << "6. Avancar Horas\n";
        std::cout << "7. Relatar Estado\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            std::string nome;
            std::cout << "\nDigite o nome da cidade: ";
            std::getline(std::cin, nome);
            controlador.cadastrarCidade(nome);
            break;
        }
        case 2:
        {
            std::string nomeOrigem, nomeDestino;
            char tipo;
            int distancia;
            std::cout << "\nDigite o nome da cidade de origem: ";
            std::getline(std::cin, nomeOrigem);
            std::cout << "Digite o nome da cidade de destino: ";
            std::getline(std::cin, nomeDestino);
            std::cout << "Digite o tipo de trajeto (A para Aquatico, T para Terrestre): ";
            std::cin >> tipo;
            std::cout << "Digite a distancia em km: ";
            std::cin >> distancia;
            std::cin.ignore();
            controlador.cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distancia);
            break;
        }
        case 3:
        {
            std::string nome, localAtual;
            char tipo;
            int capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso;
            std::cout << "\nDigite o nome do transporte: ";
            std::getline(std::cin, nome);
            std::cout << "Digite o tipo (A para Aquatico, T para Terrestre): ";
            std::cin >> tipo;
            std::cout << "Digite a capacidade de passageiros: ";
            std::cin >> capacidade;
            std::cout << "Digite a velocidade em km/h: ";
            std::cin >> velocidade;
            std::cout << "Digite a distancia entre descansos em km: ";
            std::cin >> distancia_entre_descansos;
            std::cout << "Digite o tempo de descanso em horas: ";
            std::cin >> tempo_de_descanso;
            std::cin.ignore();
            std::cout << "Digite o nome da cidade atual: ";
            std::getline(std::cin, localAtual);
            controlador.cadastrarTransporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, localAtual);
            break;
        }
        case 4:
        {
            std::string nome, localAtual;
            std::cout << "\nDigite o nome do passageiro: ";
            std::getline(std::cin, nome);
            std::cout << "Digite o nome da cidade atual: ";
            std::getline(std::cin, localAtual);
            controlador.cadastrarPassageiro(nome, localAtual);
            break;
        }
        case 5:
        {
            std::string nomeTransporte, nomeOrigem, nomeDestino;
            std::vector<std::string> nomesPassageiros;
            int numPassageiros;
            std::cout << "\nDigite o nome do transporte: ";
            std::getline(std::cin, nomeTransporte);
            std::cout << "Digite o nome da cidade de origem: ";
            std::getline(std::cin, nomeOrigem);
            std::cout << "Digite o nome da cidade de destino: ";
            std::getline(std::cin, nomeDestino);
            std::cout << "Digite o numero de passageiros: ";
            std::cin >> numPassageiros;
            std::cin.ignore();
            for (int i = 0; i < numPassageiros; ++i) {
                std::string nomePassageiro;
                std::cout << "Digite o nome do passageiro " << i + 1 << ": ";
                std::getline(std::cin, nomePassageiro);
                nomesPassageiros.push_back(nomePassageiro);
            }
            controlador.iniciarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
            break;
        }
        case 6:
        {
            int horas;
            std::cout << "\nDigite o numero de horas a avancar: ";
            std::cin >> horas;
            controlador.avancarHoras(horas);
            break;
        }
        case 7:
        {
            controlador.relatarEstado();
            break;
        }
        case 0:
            std::cout << "\nSaindo do Sistema Controlador de Viagens\n";
            break;
        default:
            std::cout << "\nEssa opcao nao existe! Digite uma opcao valida!!\n";
        }
    } while (opcao != 0);

    return 0;
}
