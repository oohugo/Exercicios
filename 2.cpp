#include <iostream>
#include <vector>

std::vector<long> fib;

long fibonaci(long termo){
    if(fib.size() < 3){
        fib.push_back(0);
        fib.push_back(1);
        fib.push_back(1);
    }
    while(fib.size() <= termo )
        fib.push_back( fibonaci(termo-1) + fibonaci(termo-2));
    return fib[termo];
}

int main(){
    long maximo = 4000000;
    long resultado = 0;

    for(long i = 3; fibonaci(i) < maximo; i+= 3)
        resultado += fibonaci(i);

    std::cout << resultado<< "\n";
    return 0;
}
