#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

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

template<typename Number>
Number resolution(int div_cell){
    Number n=3;
    Number n1;
    int div_n=2,div_n1; 
    int count=0;  
    int exponent; 
    std::vector<int> primearray;
    primearray.push_back(2);

    for(Number i = 3;  primearray.size() < div_cell/2; i+=2)
        if(isPrime<Number>(i))
            primearray.push_back(i);

    while (count <= div_cell) {   
        n++;
        n1 = n;
        if(n1 % 2 == 0)
            n1 /= 2;
        div_n1 = 1;
        for (auto prime: primearray){
            if(prime*prime > n1){
                div_n1 *= 2; 
                break;
            }          
            exponent=1;     
            while (n1 % prime == 0) {
                exponent++;
                n1 /= prime;
            }
            if(exponent > 1)
                div_n1 *= exponent;     
            if( n1 == 1)
                break;
        }   
        count = div_n * div_n1;   
        div_n = div_n1;   
    } 
    return n*(n-1)/2;
}

int main(){
    assert(resolution<int>(5) == 28);
    std::cout << resolution<long>(500)<< "\n";
    return 0;
}

