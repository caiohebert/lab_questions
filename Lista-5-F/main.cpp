#include <iostream>
#include <set>
#include <iterator>
#include <string>
using namespace std;

int main() {
  long long balizas, msg, i, I, T, segmentos = 0;
  char estaciona;
  set <long long> avenida;
  set<long long>::iterator it;
  cin >> balizas;
  
  for(i = 0; i < balizas; i++){
    cin >> estaciona >> I >> T;
    if (estaciona == 'E'){
      avenida.insert(I);
      avenida.insert(T);
      segmentos++;
      if (avenida.count(T+1) == 1){
        segmentos--;
      }
      if (avenida.count(I-1) == 1){
        segmentos--;
      }
    }
      
    else {
      if (avenida.count(T+1) == 1){
        segmentos++;
      }
      if (avenida.count(I-1) == 1){
        segmentos++;
      }
      avenida.erase(I);
      avenida.erase(T);
      segmentos--;
    }

    cout << segmentos << endl;
  }
  
  return 0;
}