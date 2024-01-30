#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct arvore {        // classe das arvores
	string nome;
	int altura; 		
};

bool cmp(arvore i, arvore j) { 
  return (i.altura < j.altura); 
}

int main() {
  int N, C, i;
  cin >> N >> C;
  vector<arvore> v; 
  arvore x;

  for (i=0; i<N; i++){    // criar vetor com arvores diferentes
    cin >> x.nome >> x.altura;
    v.push_back(x);
  }
  stable_sort (v.begin(), v.end(), cmp);    // ordena o vetor de arvores em ordem crescente de altura

  for (i=0; i<C; i++) { 
    cout << v[(N-1)-i].nome << endl;  // imprime os elementos do vetor de acordo com C em ordem decrescente
  }
  return 0;
}