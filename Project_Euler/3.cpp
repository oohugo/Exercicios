#include <iostream>
#include <math.h>

long long maior_fator_primo(long long number){
    long long candidate_prime = std::sqrt(number);
    while(candidate_prime > 1){
        if(number % candidate_prime == 0)
            if(maior_fator_primo(candidate_prime) == 1)
                return candidate_prime;
        candidate_prime--;
    }
    return 1;
}


int main(){
    long long maximo = 600851475143 ;
    long long resultado = maior_fator_primo(maximo);
    std::cout << resultado<< "\n";
    return 0;
}
