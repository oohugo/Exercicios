#include <iostream>
#include <vector>
#include <assert.h>

template <typename Number>
Number collatz_next(Number n){
  return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

unsigned long long chain[1000000] = {0};

template <typename Number>
Number cont_chain(unsigned long long n){
  if(chain[n] != 0)
    return chain[n];
  
  unsigned long long count = 1;
  auto next = n;
  while ( next > 1)
  {
    count++;
    next = collatz_next(next);
    if(next < 1000000 && chain[next] != 0){
      count += chain[next];
      break;
    }
  }
  chain[n] = count;
  return count;
}

int main(){
  assert(collatz_next<int>(13) == 40);
  assert(collatz_next<int>(40) == 20);
  assert(cont_chain<int>(13) == 10);

  unsigned long long maior = 0;
  long seq_maior = 1;
  for(long i = 1;i < 1000000; i++){
    auto aux = cont_chain<unsigned long long>(i);
    if(aux > maior){
      maior = aux;
      seq_maior = i;
    }
  }

  assert(seq_maior == 837799);
  return 0;
}

