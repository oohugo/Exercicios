#include <iostream>
#include <vector>

long long f(long long L,long long nMax=45000){
    std::vector<long long> d (nMax);
    for (auto n = 1; n < nMax; n++){
        for (auto j = n; j <  nMax; j += n){
            d[j]+= 1;
        }
        auto nDiv = n%2==0  ? d[n-1] * d[n/2] : d[(n-1)/2] * d[n];
        if (nDiv > L)
          return (n*(n-1)/2);
    }
}

int main(){
  std::cout << f(5)<< " " << f(500);
}