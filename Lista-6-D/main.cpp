#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
  int n_alunos, n_aulas, i, j, aluno, P;
  map <int, int> presenca;
  map <int, int> :: iterator it;
  cin >> n_alunos >> n_aulas; 

  // criando a lista de presença
  for (i = 0; i < n_alunos; i++){
    cin >> aluno;
    presenca[aluno] = 0;
  }

  // contabilizando as presenças
  for (i = 0; i < n_aulas; i++){
    cin >> P;
    for (j = 0; j < P; j++){
      cin >> aluno;
      it = presenca.find(aluno);
      it -> second += 1;
    }
  }
  
  // saída
  for (it = presenca.begin(); it != presenca.end(); it++){
    // se for reprovado
    if (n_aulas - (it -> second) > n_aulas/4){
      cout << it -> first << ": RF" << endl;
    }
    // se for aprovado
    else{
      cout << it -> first << ": " << n_aulas - it -> second << endl;
    }
  }
  
  return 0;
}