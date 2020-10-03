#include <iostream>
#include <math.h>

template<typename Number>
Number sieve_sum(Number max){
    Number sieve_limit = (max-1)/2;
    bool sieve_array[sieve_limit] = {false};
    Number cross_limit = (std::sqrt(max) - 1) / 2;
    Number sum = 2;

    for(auto i = 1; i <= cross_limit; i++){
        if(!sieve_array[i])
            for(auto j = 2 * i * (i+1); j <= sieve_limit; j += 2*i+1)
                sieve_array[j] = true;
    }

    for(auto i = 1; i < sieve_limit; i++)
            if(!sieve_array[i])
                sum+=(2*i+1);
    return sum;
}

int main(){
    unsigned long long max = 2000000;

    auto sum = sieve_sum<unsigned long long>(max);

    unsigned long long resultado = 142913828922;
    std::cout << resultado - sum<<"\n";
    return 0;
}

