#include <vector>
#include "Cidade.hpp"
using namespace std;

class Buscador
{
private:
    vector<vector<double>> distancias;
    vector<int> caminho;
    int nCidades;

public:
    Buscador(int p_nCidades);
    void guarda_distancias(vector<Cidade> cidades);
    double calcula_distancia(Cidade &c1, Cidade &c2);
    std::vector<int> testa_caminhos();
    double calcula_caminho(vector<int>&caminho);

    ~Buscador();
};
