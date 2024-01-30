#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int n_planetas, n_visitas, i, imposto, posicao, custo_total = 0;
  string planeta;
  vector <string> nomes;
  vector <int> taxas;

  // construindo os vetores
  cin >> n_planetas;
  for (i=0; i < n_planetas; i++){
    cin >> planeta >> imposto;
    nomes.push_back(planeta);
    taxas.push_back(imposto);
  }

  // fazendo a conta dos impostos
  cin >> n_visitas;
  for (i=0; i < n_visitas; i++){
    cin >> planeta;
    posicao = lower_bound(nomes.begin(), nomes.end(), planeta) - nomes.begin();
    custo_total += taxas[posicao];
  }

  // imprimindo o imposto total pago
  cout << custo_total << endl;
  
  return 0;
}