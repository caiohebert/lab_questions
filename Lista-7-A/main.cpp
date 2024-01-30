#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n_feiticos, i, n_proibidos, consultas;
  string feitico, proibido, consulta;
  vector <string> feiticos, proibidos;
  
  // criando mapa de feitiços
  cin >> n_feiticos;
  for (i=0; i < n_feiticos; i++){
    cin >> feitico;
    feiticos.push_back(feitico);
  }

  // criando mapa de feitiços
  cin >> n_proibidos;
  for (i=0; i < n_proibidos; i++){
    cin >> proibido;
    proibidos.push_back(proibido);
  }

  // consultando se o feitiço "consulta" é proibido ou não
  cin >> consultas;
  for (i=0; i < consultas; i++){
    cin >> consulta;
    if (binary_search(feiticos.begin(), feiticos.end(), consulta) == 1){
      cout << "Geral" << endl;
    }
    else{
      cout << "Proibido" << endl;
    }
  }
  
  return 0;
}