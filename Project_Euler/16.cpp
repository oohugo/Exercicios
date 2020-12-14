#include <assert.h>
#include "digits.cpp"

template <typename Number>
Number power_of2(int exp){
  Number p(2);
  for(int i = 1; i < exp; i++)
    p = p + p;
  return p;
}

int main(){
  
  assert(power_of2<int>(2) == 4);
  assert(power_of2<Digits>(3) == Digits(8));
  assert(power_of2<Digits>(1000).sum_digits() == 1366);
  
  return 0;
}