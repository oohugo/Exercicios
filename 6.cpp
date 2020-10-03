#include <iostream>

template <typename Number>
Number soma_n_primeiros(Number ultimo){
    Number resultado;
    resultado = ((1+ ultimo) * ultimo)/(2);
    return resultado;
}

template <typename Number>
Number soma_n2_primeiros(Number ultimo){
    Number resultado;
    resultado = ((2 * ultimo + 1) * (ultimo + 1) * ultimo)/(6);
    return resultado;
}

int main(){
    long long max = 100;
    long long resultado = 1;
    resultado = soma_n_primeiros<long long>(max) * soma_n_primeiros<long long>(max) - soma_n2_primeiros<long long>(max);
    std::cout << resultado<< "\n";
    return 0;
}
