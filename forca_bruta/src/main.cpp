#include <iostream>
#include <fstream>
#include <vector>
#include "Cidade.hpp"
#include "Buscador.hpp"

int main(){

    std::ifstream file("../test/cities.txt");

    std::vector<Cidade> cidades;
    int nCidades;

    file >> nCidades;

    for (int i = 0; i < nCidades; i++){ //Leitura do arquivo
        int x, y;
        file >> x;
        file >> y;

        cidades.push_back(Cidade(x,y));
    }

    Buscador buscador = Buscador(nCidades);

    buscador.guarda_distancias(cidades);

    std::vector<int> melhorC = buscador.menor_caminho();

    for (int i : melhorC){
        std::cout << i << " ";
    }
    std::cout << "\nDistância: " << buscador.calcula_caminho(melhorC) << "\n";

    file.close();
    return 0;
}