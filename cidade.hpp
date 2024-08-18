#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <string>
#include <vector>

class Cidade {
private:
    std::string nome;
    std::vector<std::pair<Cidade*, int>> distancias;
public:
    Cidade(std::string nome);
    std::string getNome();
    void adicionarDistancia(Cidade* destino, int distancia);
    int obterDistanciaPara(Cidade* destino);
};

#endif
