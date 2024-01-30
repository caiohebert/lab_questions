#include <iostream>
#include <set>
#include <iterator>
#include <string>
using namespace std;

int main() {
  int N, msg, i, j, qtd;
  string palavrao, palavra;
  cin >> N >> msg;

  set <string> dicionario, frases, ofensivas, n_ofensivas;
  set<string>::iterator it;

  for (i = 0; i < N; i++){
    cin >> palavrao;
    dicionario.insert(palavrao);
  }

  // criando conjunto de frases
  for (i = 0; i < msg; i++){
    cin >> qtd; 
    for (j = 0; j < qtd; j++){
      cin >> palavra;
      if (dicionario.count(palavra) == 1){
        cout << "bobba" << " ";
        ofensivas.insert(palavra);
      }
      else{
        cout << palavra << " ";
        n_ofensivas.insert(palavra);
      }
    }
    cout << endl;
  }

  cout << n_ofensivas.size() << " " << ofensivas.size() << endl;
  
  return 0;
}