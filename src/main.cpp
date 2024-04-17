#include <iostream>
#include <fstream>
#include "Cidade.hpp"
#include "Visitas.hpp"

int main(){

    std::ifstream file("./test/cities.txt");

    int nCidades;
    int inicio;

    std::vector<Cidade> cidades;

    file >> nCidades;
    file >> inicio;

    for (int i = 0; i < nCidades; i++){ //Leitura do arquivo
        int x, y;
        file >> x;
        file >> y;

        cidades.push_back(Cidade(x,y));
    }
    Visitas visitas = Visitas(nCidades,inicio, cidades);

    visitas.tracarCaminho();

    std::vector<Visitas> v;

    double media = 0;
    double pesoMax = 0, pesoMin = 0;
    int melC = 0, pioC = 0;

    for(int i = 0; i < nCidades; i++){ //Calcula o caminho com base em cada cidade inicial
        v.push_back(Visitas(nCidades, i, cidades));
        v[i].tracarCaminho();
        double peso = 0;
        std::vector<int> c = v[i].getCaminho();
        for (int j = 0; j < nCidades; j++){
            peso += v[i].getDistancia(c[j], c[j+1]);
        }
        media += peso;
        pioC = peso > pesoMax ? i:pioC;
        pesoMax = peso > pesoMax ? peso:pesoMax;
        
        melC = peso < pesoMin || pesoMin == 0? i:melC;
        pesoMin = peso < pesoMin || pesoMin == 0? peso:pesoMin;
        
    }
    media /= nCidades;
    std::cout<<"Min: "<<pesoMin << "\n";
    std::cout<<"Max: "<<pesoMax << "\n";
    std::cout<<"Med: "<<media << "\n";

    std::cout<<"Melhor começo: "<< melC << std::endl;
    std::cout<<"Pior começo: "<< pioC << std::endl;

    // std::cout<<"Melhor caminho: ";
    // for (int c : v[melC].getCaminho())
    //     std::cout << c << " ";

    // std::cout<<"\nPior caminho: ";
    // for (int c : v[pioC].getCaminho())
    //     std::cout << c << " ";
    // std::cout<<"\n";

    // double peso = 0;
    // std::vector<int> c = visitas.getCaminho();
    // for (int i = 0; i < nCidades; i++){
    //     peso += visitas.getDistancia(c[i], c[i+1]);
    //     std::cout << c[i] << " ";
    // }
    // std::cout<< c[nCidades] << std::endl << peso << std::endl;

    file.close();

    return EXIT_SUCCESS;
}