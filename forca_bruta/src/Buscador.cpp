#include <math.h>
#include <iostream>
#include "Buscador.hpp"

Buscador::Buscador(int p_nCidades)
{
    nCidades = p_nCidades;
    for (int i = 0; i < nCidades; i++){
        caminho.push_back(i);
    }
}

void Buscador::guarda_distancias(vector<Cidade> &cidades){

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

std::vector<int> Buscador::menor_caminho(){

    double menorDist = calcula_caminho(this->caminho);
    std::vector<int> menorC = this->caminho;

    permutar_caminhos(this->caminho, 0, menorDist, menorC);

    menorC.push_back(menorC[0]);
    return menorC;
}
void Buscador::permutar_caminhos(std::vector<int> &c, int k, double &menorDist, std::vector<int>&melhorC){

    if(k == c.size()){

        double dist = calcula_caminho(c);

        if(dist < menorDist){
            menorDist = dist;
            melhorC = c;
        }
    }
    else{
        for(int i = k; i < c.size(); i++){
            troca(c, i, k);
            permutar_caminhos(c,k+1, menorDist, melhorC);
            troca(c, k, i);
        }
    }
}
void Buscador::troca(std::vector<int> &c, int n1, int n2){
    int aux = c[n1];
    c[n1] = c[n2];
    c[n2] = aux;
}

double Buscador::calcula_distancia(Cidade &c1, Cidade &c2){
    return std::sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

double Buscador::calcula_caminho(vector<int>&caminho){
    
    double dist = 0;
    for(int i = 0; i < nCidades -1; i++){
        dist += distancias[caminho[i]][caminho[i+1]];
        
    }
    
    dist += distancias[caminho[nCidades -1]][caminho[0]];
    
    return dist;
}

