#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <set>
using namespace std;

int main() {
  int n_linhas, i, j;
  string linha, palavra;
  cin >> n_linhas;
  cin.ignore();
  map <string, int> mapa;
  map <string, int>::iterator it;
  set <string> repetidas;
  set <string>::iterator it1;    

  for (i = 0; i < n_linhas; i++){
    getline(cin, linha);
    for (j = 0; j < linha.size(); j++){
      if (linha[j] == ' '){
        if (mapa.count(palavra) == 0){
          mapa[palavra] = 1;
        }
        else{
          repetidas.insert(palavra);
          mapa.erase(palavra);
        }
        palavra = "";
      }
      
      if (linha[j] != ' ') {
        palavra += linha[j];
      }

      if(j == linha.size() - 1){  
        if (mapa.count(palavra) == 0){
          mapa[palavra] = 1;
        }
        else{
          repetidas.insert(palavra);
          mapa.erase(palavra);
        }
        palavra = "";
      }
    }
  }

  // verificando se tem repetidas e tirando
  for (it1 = repetidas.begin(); it1 != repetidas.end(); it1++){
    if (mapa.count(*it1) == 1){
      mapa.erase(*it1);
    }
  }

  // imprimindo
  cout << mapa.size() << endl; 
  if (mapa.size() != 0){
    for(it = mapa.begin(); it != mapa.end(); it++){ 
      cout << it->first  << endl;
    }
  }

  return 0; 
}