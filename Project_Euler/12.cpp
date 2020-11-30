#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>

long triangleNumber(int index){
    long somaPA = ((index + 1) * index) / 2;
    return somaPA;
}


template <typename Number>
Number maior_fator_primo(Number number){
    Number candidate_prime = std::sqrt(number);
    while(candidate_prime > 1){
        if(number % candidate_prime == 0)
            if(maior_fator_primo(candidate_prime) == 1)
                return candidate_prime;
        candidate_prime--;
    }
    return 1;
}

static std::vector<long> primes {2,3};

void get_primes(long number){
    auto i = primes.back() + 1;
    bool eprimo;
    long max_p;
    while(primes.back() < number/2){
        eprimo = true;
        max_p = sqrt(i)+1;
        for(auto j = 0; j < primes.size() && primes[j] < max_p; j++){
            if(i % primes[j] == 0 ){
                eprimo = false;
                break;
            }
        }
        if(eprimo)
            primes.push_back(i);
        i++;
    }
}

std::vector<int> factorization(long number){
    get_primes(number);
    std::vector<int> factors (number/2) ;
    for(auto i = 0; i < factors.size(); i++){
        while (number > 1 && number % primes[i] ==0)
        {
            factors[i]++;
            number /= primes[i];
        }   
    }
    return factors;
}

int numberOfDivisor(long n){
    auto p = maior_fator_primo<long>(n);
    int sum = 2;
    while(n > 1 && p > 1)
    {
        sum++;
        while (n % p == 0){
            n = n / p;
            sum++;
        }
        p = maior_fator_primo<long>(n);
    }
    return sum;
}

long fistNumberMoreDivisor(long max_divisor){
    long candidate_divisor = 1;
    long i = 1;
    long number = triangleNumber(i);
    while (candidate_divisor < max_divisor)
    {
        number = triangleNumber(i);
        candidate_divisor = numberOfDivisor(number);
        i++;
    }
    return number;
}

void test_triangleNumber(){
    int lista[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    for(int i = 1; i <= 10;i++){
        assert(triangleNumber(i) == lista[i-1]);
    }
}

void test_numberOfDivisor(){
    assert(numberOfDivisor(28) == 5);
}

void test_fistNumberMoreDivisor(){
    assert(fistNumberMoreDivisor(5) == 28);
} 

void test_primes(){
    get_primes(28);
    assert( primes[0] == 2);
    assert( primes[1] == 3);
    assert( primes[2] == 5);
    assert( primes[3] == 7);
    assert( primes[4] == 11);
    assert( primes[5] == 13);
}

void test_factorization(){
    auto f = factorization(28);
    assert( f[0] == 2);
    assert( f[1] == 0);
    assert( f[2] == 0);
    assert( f[3] == 1);
}

void testes(){
    test_triangleNumber();
    test_fistNumberMoreDivisor();
    test_numberOfDivisor();
    test_primes();
    test_factorization();
}

int main(){
    testes();
    // std::cout << fistNumberMoreDivisor(500)  << "\n";
    return 0;
}

