#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int n_planetas, i, j, n_treinos, distancia, posicao1, posicao2, total = 0;
  string planeta, treino;
  vector <string >lista, yoda;
  vector<int> linha;
  vector<vector <int> > matriz;
  
  // construindo vetor de planetas
  cin >> n_planetas;
  for (i=0; i < n_planetas; i++){
    cin >> planeta;
    lista.push_back(planeta);
  }

  // construindo vetor de treinos
  cin >> n_treinos;
  for (i=0; i < n_treinos; i++){
    cin >> treino;
    yoda.push_back(treino);
  }

  // construindo matriz
  for (i=0; i < n_planetas; i++){
    linha.clear();
    for (j=0; j < n_planetas; j++){
      cin >> distancia;
      linha.push_back(distancia);
    }
    matriz.push_back(linha);
  }

  // calculando distancia percorrida
  for (i=0; i < n_treinos; i++){
    // indice do planeta no vetor planetas
    if (i == 0){
      posicao2 = lower_bound(lista.begin(), lista.end(), yoda[i]) - lista.begin();
      total += matriz[0][posicao2];
    }
    else{
      posicao1 = lower_bound(lista.begin(), lista.end(), yoda[i-1]) - lista.begin();
      posicao2 = lower_bound(lista.begin(), lista.end(), yoda[i]) - lista.begin();
      total += matriz[posicao1][posicao2];
    }
  }

  cout << total << endl; 
  
  return 0;
}