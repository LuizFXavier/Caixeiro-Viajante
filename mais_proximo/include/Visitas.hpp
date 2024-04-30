#pragma once

#include <vector>
#include "Cidade.hpp"

class Visitas
{
private:
    int inicio;
    int nCidades;
    std::vector<int> caminho;
    std::vector<bool> visitada;
    std::vector<std::vector<double>> distancias;
public:
    Visitas(int nCidades, std::vector<Cidade> cidades);
    Visitas(int nCidades, int inicio, std::vector<Cidade> cidades);
    double calcDist(Cidade c1, Cidade c2);
    double getDistancia(int c1, int c2);
    void guardarDistancias(std::vector<Cidade> cidades);
    void guardarDistancias(std::vector<std::vector<double>> distancias);
    std::vector<std::vector<double>> getDistancia();
    void reiniciarCaminho(int inicio);
    void tracarCaminho();
    void melhorarRota(std::vector<int>& c, int maxTrocas, int testes);
    std::vector<int> getCaminho();
    int maisProx(int c);
    ~Visitas();
};
