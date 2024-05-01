#include <vector>
#include "Cidade.hpp"
using namespace std;

class Buscador
{
private:
    vector<int> caminho;
    int nCidades;

public:
    vector<vector<double>> distancias;
    Buscador(int p_nCidades);
    void guarda_distancias(vector<Cidade> &cidades);
    double calcula_distancia(Cidade &c1, Cidade &c2);
    std::vector<int> menor_caminho();
    double calcula_caminho(vector<int>&caminho);

    ~Buscador(){};
private:
    void permutar_caminhos(std::vector<int> &c, int k, double &menorDist, std::vector<int> &melhorC);
    void troca(std::vector<int> &c, int n1, int n2);

};
