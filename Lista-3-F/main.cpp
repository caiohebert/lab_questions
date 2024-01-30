#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct pokemon{
  string nome;
  int level;
};

bool cmpN(pokemon i, pokemon j) {    // função p ordenar o nome
  return (i.nome < j.nome); 
}

bool cmpL(pokemon i, pokemon j) {    // função p ordenar o nivel
  return (i.level < j.level); 
}

int main() {
  int Q;
  char T, S;
  cin >> Q >> T >> S;
  vector<pokemon> v; 
  pokemon x;

  for (int i=0; i<Q ; i++) {     // cria o vetor
    cin >> x.nome >> x.level;
    v.push_back(x);
  }
  
  if (T == 'N'){                 // ordena por nome
    if (S == 'C'){                    // nome em ordem crescente
      stable_sort (v.begin(), v.end(), cmpN);
      for(int i=0; i<Q ; i++) {
        cout << v[i].nome << " " << v[i].level << endl; 
      }
    }
    else{                             // nome em ordem decrescente
      stable_sort (v.begin(), v.end(), cmpN);
      for(int i = Q-1; i>-1 ; i--) {
        cout << v[i].nome << " " << v[i].level << endl; 
      }
    } 
  }

  else {                         // ordena por nível
    if (S == 'C'){                    // nivel em ordem crescente
      stable_sort (v.begin(), v.end(), cmpL);
      for(int i=0; i<Q ; i++) {
        cout << v[i].nome << " " << v[i].level << endl;
      }
    }
    else {                            // nivel em ordem decrescente
      stable_sort (v.begin(), v.end(), cmpL);
      for(int i = Q-1; i>-1 ; i--) {
        cout << v[i].nome << " " << v[i].level << endl;
      }
    } 
  }
  return 0;