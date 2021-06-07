#include <iostream>
#include <math.h>
#include <vector>

std::vector<long long> primo_ate(long long number){
    std::vector<long long> primos;
    primos.push_back(2);
    primos.push_back(3);
    bool eprimo;
    for(long long i = 4; primos.size() < number; i++){
        eprimo = true;
        for(auto j = primos.begin(); j != primos.end() && *j <= std::sqrt(i); ++j)
            if(i % *j == 0){
                eprimo = false;
                break;
            }
        if(eprimo)
            primos.push_back(i);
    }
    return primos;
}

template<typename Number>
bool isPrime(Number number){
    if (number==1)
        return false;
    if (number< 4)
        return true;
    if (number % 2 ==0)
        return false;
    if (number < 9)
        return true;
    if (number % 3 ==0)
        return false;
    Number max = std::sqrt(number);

    for(int i = 5; i<=max; i+=6)
        if(number % i == 0 || (number % (i+2) == 0))
            return false;

    return true;
}

int main(){

    long long max = 10001;
//    auto primos = primo_ate(max);
//    long long resultado = primos.back();


    long count=1;
    long candidate=1;
    while(count < max){
        candidate+=2;
        if (isPrime<long>(candidate))
            count++;
    }

    auto resultado = candidate;

    std::cout << resultado<< "\n";
    return 0;
}
