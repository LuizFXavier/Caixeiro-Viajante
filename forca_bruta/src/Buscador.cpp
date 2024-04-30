#include <math.h>
#include "Buscador.hpp"

Buscador::Buscador(int p_nCidades)
{
    nCidades = p_nCidades;

    for (int i = 0; i < nCidades; i++){
        caminho.push_back(i);
    }
    caminho.push_back(caminho[0]);
}

void Buscador::guarda_distancias(vector<Cidade> cidades){

    for (int i = 0; i < this->nCidades; i++){

        std::vector <double> c;
        c.resize(nCidades);
        for (int j = 0; j < this->nCidades; j++){
            if (j > i)
                c[j] = calcula_distancia(cidades[i], cidades[j]);
            else if (j < i)
                c[j] = this->distancias[j][i];
            else
                c[j] = 0;
            
        }
        this->distancias.push_back(c);
    }
}

std::vector<int> Buscador::testa_caminhos(){

    double menorDist = calcula_caminho(this->caminho);
    std::vector<int> menorC = this->caminho;

}

double Buscador::calcula_distancia(Cidade &c1, Cidade &c2){
    return std::sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

double Buscador::calcula_caminho(vector<int>&caminho){

}

