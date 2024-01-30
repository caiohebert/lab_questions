#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
  int N, i, j, codigo, prox, qtd;
  cin >> N;
  set <int> professor;
  set <int> alunos;
  set<int>::iterator it;
  
  for (i = 0; i < N; i++){
    cin >> codigo;
    professor.insert(codigo);
  }
  
  cin >> qtd;
  for (i = 0; i < qtd; i++){
    cin >> codigo;
    alunos.insert(codigo);
  }

  // percorre o conjunto do professor e verifica as igualdades pra remover
  it = professor.begin();
  for (i = 0; i < N; i++) {
    if (alunos.count(*it) == 1){
      it = next(it);
      alunos.erase(alunos.find(*prev(it)));
      professor.erase(*prev(it));
    }
    else {
      it++;
    }
  }
  
  // impressão: alunos - sobrou, professor - faltou
  if (alunos.size() == 0 && professor.size() == 0){
    cout << "Acertou tudo" << endl;
  }
    
  else{
    cout << "Sobrou:" << endl;
    for(it = alunos.begin(); it != alunos.end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  
    cout << "Faltou:" << endl;
    for(it = professor.begin(); it != professor.end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}