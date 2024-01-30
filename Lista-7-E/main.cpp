#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int largura, comprimento, i, j, k, altura, consultas, horas_passadas, inundados;
  vector<int>linha;
  vector<vector <int> > matriz;

  cin >> largura >> comprimento;
  for (i=0; i < largura; i++){
    linha.clear();
    for (j=0; j < comprimento; j++){
      cin >> altura;
      linha.push_back(altura);
    }
    stable_sort(linha.begin(), linha.end());
    matriz.push_back(linha);
  }
  
  cin >> consultas;
  for (i=0; i < consultas; i++){
    cin >> horas_passadas;
    inundados = 0;
    for (j=0; j < largura; j++){
      for (k=0; k < comprimento; k++){
        if(matriz[j][k] <= horas_passadas){
          inundados++;
        }
      }
    }
    cout << inundados << endl;
  }

  return 0;
}