#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  int n_planetas, i, planeta, P;
  vector <int> lista;
  vector <int> :: iterator it;
  
  // criando vetor
  cin >> n_planetas;
  for (i=0; i < n_planetas; i++){
    cin >> planeta;
    lista.push_back(planeta);
  }

  // fazendo a busca
  while (true){
    cin >> P;
    if (P == 0){
      break;
    }
    if (binary_search(lista.begin(), lista.end(), P) == 1){
      it =  lower_bound(lista.begin(), lista.end(), P);
      cout << it - lista.begin() << endl;
    }
    else{
      cout << "Nao foi visitado ainda." << endl;
    }
  }
  
  return 0;
}