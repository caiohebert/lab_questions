#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main() {
  int N, i, M, j;
  string termo, traducao, palavra, frase_traduzida;
  map <string, string> dicionario;
  map <string, string>::iterator it;
  cin >> N;

  
  for (i = 0; i < N; i++){
    cin >> termo >> traducao;
    dicionario[termo] = traducao;
  }

  cin >> M;
  for (j = 0; j < M; j++){
    cin >> palavra;
    if (dicionario.count(palavra) == 1){
      it = dicionario.find(palavra);
      frase_traduzida += it -> second;
      frase_traduzida += ' ';
    }
    else{
      frase_traduzida += palavra;
      frase_traduzida += ' ';
    }
  }
  
  cout << frase_traduzida << endl;
  return 0;
}