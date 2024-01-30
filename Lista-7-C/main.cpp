#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;


int main() {
  int qtd_livros, i, A, posicao, status;
  string requisicao, codigo;
  vector <string> acervo;
  vector <int> situacao;
  vector <string> :: iterator it;
 

  // construindo vetores
  cin >> qtd_livros;
  for (i=0; i < qtd_livros; i++){
    cin >> codigo >> status;
    acervo.push_back(codigo);
    situacao.push_back(status);
  }

  // fazendo a busca
  cin >> A;
  for (i=0; i < A; i++){
    cin >> requisicao;
    if (binary_search(acervo.begin(), acervo.end(), requisicao) == 1){
      posicao = lower_bound(acervo.begin(), acervo.end(), requisicao) - acervo.begin();
      if (situacao[posicao] == 1){
        cout << "Disponivel" << endl;
      }
      else{
        cout << "Emprestado" << endl;
      }
    }
    else{
      cout << "Nao encontrado" << endl;
    }
  }
  
  return 0;
}