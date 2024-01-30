#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

int main() {
  int F, i, qtd, validade, N, Q, D, tinha = 0;
  char L;
  cin >> F;
  stack<pair<int, int>> fenos;
  stack<pair<int, int>> aux;

  for (i = 0; i < F; i++) {
    cin >> qtd >> validade;
    fenos.push(make_pair(qtd, validade));
  }

  cin >> N;

  // operações com a pilha
  for (i = 0; i < N; i++) {
    cin >> L >> Q;
    if (L == 'C') {
      // para compras temos que subtrair as quantidades, se der 0, retira o feno.
      while (Q > 0 && !fenos.empty()) {
        pair<int, int> par = fenos.top();
        if (par.first > Q) {
          par.first -= Q;
          fenos.pop();
          fenos.push(par);
          break;
        } else {
          fenos.pop();
          Q -= par.first;
        }
      }
    }

    if (L == 'V') {
      cin >> D;
      // caso em que a validade do feno novo é menor que a do topo da pilha, empilha.
      if (fenos.empty() == true || fenos.top().second > D) {
        fenos.push(make_pair(Q, D));
        continue;
      }
      
      // caso em que a validade do feno novo é igual a do topo, soma a quantidade.
      if (fenos.top().second == D) {
        fenos.top().first += Q;
        continue;
      }

      // caso em que a validade do feno novo é maior que a do topo, precisa procurar na pilha o lugar certo na ordem e alocar.
      if (fenos.top().second < D) {
        // encontra o ponto em que um feno tem validade maior ou igual ao feno novo, jogando os de cima numa pilha auxiliar
        while (fenos.empty() == false && fenos.top().second < D) { 
          aux.push(fenos.top());
          fenos.pop();
        }
        // empilha o feno novo em cima do que tem validade maior ou igual (n precisei somar as quantidades se forem iguais kkk)
        fenos.push(make_pair(Q, D));

        // retorna os fenos da auxiliar para a principal
        while (!aux.empty()) {
          fenos.push(aux.top());
          aux.pop();
        }
      }
    }
  }

  // imprimir estado da pilha:
  if (fenos.empty() == false) {
    while (!fenos.empty()) {
      cout << fenos.top().first << " " << fenos.top().second << endl;
      fenos.pop();
    }
  }

  else {
    cout << "Sem estoque" << endl;
  }

  return 0;
}