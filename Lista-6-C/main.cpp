#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main() {
  int n_palavras, n_mensagens, i, tamanho_msg, j;
  string palavra, traducao, palavra2, frase_traduzida;
  char fonte, destino;
  map <string, string> dicionario_A, dicionario_B;
  map <string, string> :: iterator it;

  cin >> n_palavras >> n_mensagens;
  
  // construindo os dicionarios
  for (i = 0; i < n_palavras; i++){
    cin >> palavra >> traducao;
    dicionario_A[palavra] = traducao;
    dicionario_B[traducao] = palavra;
  }
  
  // entrada das mensagens
  for (i = 0; i < n_mensagens; i++) {
    cin >> fonte >> destino >> tamanho_msg;

    frase_traduzida = "";
    if (fonte == 'A' && destino == 'B'){
      for (j = 0; j < tamanho_msg; j++){
        cin >> palavra2;
        if (dicionario_A.count(palavra2) == 1){
          it = dicionario_A.find(palavra2);
          frase_traduzida += it -> second;
          frase_traduzida += ' ';
        }
        else{
          frase_traduzida += palavra2;
          frase_traduzida += ' ';
        }
      }
    }
    
    if (fonte == destino){
      for (j = 0; j < tamanho_msg; j++){
        cin >> palavra2;
        frase_traduzida += palavra2;
        frase_traduzida += ' ';
      }
    }

    if (fonte == 'B' && destino == 'A'){
      for (j = 0; j < tamanho_msg; j++){
        cin >> palavra2;
        if (dicionario_B.count(palavra2) == 1){
          it = dicionario_B.find(palavra2);
          frase_traduzida += it -> second;
          frase_traduzida += ' ';
        }
        else{
          frase_traduzida += palavra2;
          frase_traduzida += ' ';
        }
      }
    }
    cout << frase_traduzida << endl;
  }
  
  return 0;
}