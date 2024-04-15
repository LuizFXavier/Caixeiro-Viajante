#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int posMin(vector<int> c, vector<int> caminho);
void tracarCaminho(vector<int> &caminho, int cidade, int ordem);

int main(){

    vector<vector<int>> distCidades;

    vector<int> caminho;

    int nCidades;

    std::ifstream file("./test/cities.txt");

    file >> nCidades;

    caminho.resize(nCidades);
    for(int i = 0; i < nCidades; i++){

        vector<int> c;
        c.resize(nCidades);
        for(int j = i; j < nCidades; j++){
            
            if(i != j){
                file >> c[j];
            }
            else
                c[j] = 0;

            
        }
        for(int j = i; j > 0; j--)
            c[i - j] = distCidades[i - j][i];

        caminho[i] = -1;
        distCidades.push_back(c);
    }

    for(vector<int>dist : distCidades){
        for (int d : dist){
            cout << d << " ";
        }
        cout << endl;
    }
    
    bool rodando = true;
    int ultimaC = 0;

    caminho[0] = 0;

    vector<int> path;
    path.push_back(0);

    for (int i = 1; i < nCidades; i++)
    {
        int minPos = posMin(distCidades[ultimaC], caminho);
        tracarCaminho(caminho, minPos, i);
        // caminho[minPos] = i;
        // cout << distCidades[ultimaC][minPos] << " ";

        for(int c : caminho){
        cout << c << " ";
        }
        cout << endl;
        
        ultimaC = minPos;
        path.push_back(ultimaC);
    }
    for(int c : path){
        cout << c << " ";
    }
    int peso = 0;
    
    for(int i = 0; i < nCidades - 1; i++){
        peso += distCidades[path[i]][path[i+1]];
    }
    peso += distCidades[path[nCidades-1]][0];

    cout<< endl << peso << endl;

    return EXIT_SUCCESS;
}
void tracarCaminho(vector<int> &caminho, int cidade, int ordem){
    caminho[cidade] = ordem;
}

int posMin(vector<int> dist, vector<int> caminho){

    int min = 0;

    for(int i = 0; i < dist.size(); i++){
        
        // cout << (caminho[i] < 0) << " " << (dist[min] > dist[i] || min == 0);
        // cout << endl;
        if(caminho[i] < 0 && ((dist[min] > dist[i] || min == 0) && dist[i] != 0)){
            min = i;
        }
    }

    return min;
}