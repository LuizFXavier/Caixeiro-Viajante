#include <iostream>
#include <fstream>
#include "Cidade.hpp"
#include "Visitas.hpp"

int main(){

    std::ifstream file("../test/cities.txt");

    int nCidades;
    int inicio;

    std::vector<Cidade> cidades;

    file >> nCidades;

    for (int i = 0; i < nCidades; i++){ //Leitura do arquivo
        int x, y;
        file >> x;
        file >> y;

        cidades.push_back(Cidade(x,y));
    }
    Visitas visitas = Visitas(nCidades, cidades);

    visitas.guardarDistancias(cidades);

    double media = 0;
    double pesoMax = 0, pesoMin = 0;
    int melC = 0, pioC = 0;

    for(int i = 0; i < nCidades; i++){ //Calcula o caminho com base em cada cidade inicial
        visitas.reiniciarCaminho(i);
        visitas.tracarCaminho();
        // std::cout<<"Inicio em "<< i << "\n";
        double peso = 0;
        std::vector<int> c = visitas.getCaminho();
        
        for (int j = 0; j < nCidades; j++){
            peso += visitas.getDistancia(c[j], c[j+1]);
        }
        media += peso;
        pioC = peso > pesoMax ? i:pioC;
        pesoMax = peso > pesoMax ? peso:pesoMax;
        
        melC = peso < pesoMin || pesoMin == 0? i:melC;
        pesoMin = peso < pesoMin || pesoMin == 0? peso:pesoMin;
        
    }

    // media /= nCidades;
    // std::cout<<"Max: "<<pesoMax << "\n";
    // std::cout<<"Med: "<<media << "\n";

    // std::cout<<"Melhor começo: "<< melC << std::endl;
    // std::cout<<"Pior começo: "<< pioC << std::endl;

    visitas.reiniciarCaminho(melC);
    visitas.tracarCaminho();

    for (int i : visitas.getCaminho()){
        std::cout << i << " ";
    }
    std::cout<< "\n";
    std::cout<<"Distância: "<<pesoMin << "\n";

    file.close();

    return EXIT_SUCCESS;
}