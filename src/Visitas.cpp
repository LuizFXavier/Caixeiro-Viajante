#include <math.h>
#include <iostream>
#include "Visitas.hpp"

Visitas::Visitas(int nCidades, int inicio, std::vector<Cidade> cidades)
{

    this->inicio = inicio;
    this->caminho.push_back(inicio);

    this->nCidades = nCidades;

    this->visitada.resize(nCidades);

    this->guardarDistancias(cidades);

    this->visitada[this->inicio] = true;
}
Visitas::Visitas(int nCidades, std::vector<Cidade> cidades)
{
    this->inicio = 0;
    this->caminho.push_back(inicio);

    this->nCidades = nCidades;

    this->visitada.resize(nCidades);

    this->guardarDistancias(cidades);

    this->visitada[this->inicio] = true;
}

std::vector<int> Visitas::getCaminho(){
    return this->caminho;
}

double Visitas::calcDist(Cidade c1, Cidade c2){
    return std::sqrt(pow(c1.getX() - c2.getX(), 2) + pow(c1.getY() - c2.getY(), 2));
}

void Visitas::guardarDistancias(std::vector<Cidade> cidades){

    for (int i = 0; i < this->nCidades; i++){

        std::vector <double> c;
        c.resize(nCidades);
        for (int j = 0; j < this->nCidades; j++){
            if (j > i)
                c[j] = calcDist(cidades[i], cidades[j]);
            else if (j < i)
                c[j] = this->distancias[j][i];
            else
                c[j] = 0;
            
        }
        this->distancias.push_back(c);
        this->visitada[i] = false;
    }
}
void Visitas::tracarCaminho(){

    int ultimaC = this->inicio;
    int minPos;

    for (int i = 1; i < this->nCidades; i++){
        minPos = this->maisProx(ultimaC);
        this->visitada[minPos] = true;
        this->caminho.push_back(minPos);
        ultimaC = minPos;
        // for (bool b : visitada)
        //     std::cout << b << " ";
        // std::cout <<std::endl;
    }
    this->caminho.push_back(inicio);
}

int Visitas::maisProx(int c){

    int min = 0;
    for(int i = 0; i < this->nCidades; i++){
        if(!this->visitada[i] && ((this->distancias[c][min] > this->distancias[c][i] || min == 0) && this->distancias[c][i] != 0))
            min = i;
    }
    return min;
}

double Visitas::getDistancia(int c1, int c2){
    return this->distancias[c1][c2];
}

Visitas::~Visitas()
{
}