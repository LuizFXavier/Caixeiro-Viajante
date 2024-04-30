#include <math.h>
#include <iostream>
#include "Visitas.hpp"

Visitas::Visitas(int nCidades, int inicio, std::vector<Cidade> cidades)
{

    this->inicio = inicio;
    this->caminho.push_back(inicio);

    this->nCidades = nCidades;

    this->visitada.resize(nCidades);
    this->visitada[this->inicio] = true;
}
Visitas::Visitas(int nCidades, std::vector<Cidade> cidades)
{
    this->inicio = 0;
    this->caminho.push_back(inicio);

    this->nCidades = nCidades;

    this->visitada.resize(nCidades);

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
    }
}

void Visitas::guardarDistancias(std::vector<std::vector<double>> distancias){
    this->distancias = distancias;
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
std::vector<std::vector<double>> Visitas::getDistancia(){
    return this->distancias;
};
void Visitas::reiniciarCaminho(int inicio){

    this->inicio = inicio;
    this->visitada.clear();
    this->visitada.resize(this->nCidades);
    this->visitada[inicio] = true;
    this->caminho.clear();
    this->caminho.push_back(inicio);
}
void Visitas::melhorarRota(std::vector<int>& c, int maxTrocas, int testes){

    double dist1 = this->getDistancia(c[0], c[1]);
    double dist2 = this->getDistancia(c[2], c[3]);
    
    int i = 0;
    int k1 = 0;
    int k2 = k1 + 2;
    int posK1 = k1; //Melhor troca pra essa aresta;
    int posK2 = k2;
    int a1 = c[k1], a2 = c[k1 +1], b1 = c[k2], b2 = c[k2 +1];
    while (i < maxTrocas)
    {
        int t = 0;
        while (t < testes && k1+1 < this->nCidades && k2+1 < this->nCidades)
        {
            
            if(this->getDistancia(a1,b1) + this->getDistancia(a2,b2) < this->getDistancia(a1, a2) + this->getDistancia(b1, b2)){
                
                if(this->getDistancia(a1,b1) + this->getDistancia(a2,b2) < this->getDistancia(c[posK1],c[posK2]) + this->getDistancia(c[k1+1],c[k2+1])){

                    posK1 = k1;
                    posK2 = k2;
                    int aux = c[posK1];
                    c[posK1] = c[posK2];
                    c[posK2] = aux;

                    aux = c[posK1 +1];
                    c[posK1 +1] = c[posK2 +1];
                    c[posK2 +1] = aux;
                }
                
            }
            k2++;
        }
        
        
        i++;
        k1++;
    }
    
}

Visitas::~Visitas()
{
}