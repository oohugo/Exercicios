#include <iostream>
#include <math.h>
#include <vector>

std::vector<long long> primo_menorq(long long number){
    std::vector<long long> primos;
    primos.push_back(2);
    bool eprimo;
    for(long long i = 3; i < number; i ++){
        eprimo = true;
        for(auto j = primos.begin(); j != primos.end(); ++j)
            if(i % *j == 0){
                eprimo = false;
                break;
            }
        if(eprimo)
            primos.push_back(i);
    }
    return primos;
}

int main(){

    int maximo = 20;
    int limite = std::sqrt(maximo);
    long long resultado = 1

    auto primos = primo_menorq(maximo);
    std::vector<int> indices;

    for(int i = 0; primos[i] < maximo && primos[i] != 0; i++){
        indices.push_back(1);
        if(primos[i] <= limite)
            indices[i] = std::log(maximo) / std::log(primos[i]);
        resultado *= std::pow(primos[i], indices[i]);
    }

    std::cout << resultado<< "\n";
    return 0;
}
