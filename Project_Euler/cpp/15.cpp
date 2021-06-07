#include <iostream>
#include <assert.h>

template <typename Number>
Number binomial_coef(Number x,Number y){
  Number resul = 1;
  for(Number i = 0; i < y ; i++){
    resul = (resul * (x-i)) / (i+1);
  }
  return resul;
}

template <typename Number>
Number lattice_path(Number x, Number y){
  return binomial_coef<Number>(x+y,y);
}

int main(){
  std::cout << lattice_path<long>(20,20) << "\n";
  return 0;
}