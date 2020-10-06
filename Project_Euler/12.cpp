#include <iostream>
#include <cmath>


long triangleNumber(int index){
    long somaPA = ((index + 1) * index) / 2;
    return somaPA;
}


bool eprimo(long number, long* primos){
    for(int i = 0; i < std::sqrt(number)+1; i++)
        if (primos[i] != 0 && number % primos[i] == 0)
            return false;
    return true;
}

long* montaPrimos(long number){
    long max = std::sqrt(number) + 1;
    long* listaPrimos = new long[ (int)max];
    listaPrimos[0] = 2;
    listaPrimos[1] = 3;
    long quantidadePrimos = 2;
    for(int i =2;i < number; i++){

        if(eprimo(i, listaPrimos)){
            listaPrimos[quantidadePrimos] = i;
            quantidadePrimos++;
        }
    }
    return listaPrimos;
}


long* fatoracaoNumero(long number, long* primos){
    long max = std::sqrt(number) + 1;
    long* fatoracao = new long(max);
    for(int i = 0; i < max;i++){
        fatoracao[i] = 0;
        while ( ((number != 1) && (primos[i] != 0)) && number % primos[i] == 0){
            fatoracao[i]++;
            number /= primos[i];
        }
    }
    return fatoracao;
}

long contaDivisores(long number,long* primos){
    long quantidade =1;

    if(eprimo(number, primos))
        return 2;

    long * numberFatorado = fatoracaoNumero(number, primos);
    for(int i = 0; i < std::sqrt(number); i++){
        if(numberFatorado[i] != 0){
            quantidade *= (numberFatorado[i] + 1);
        }
    }
    delete(numberFatorado);
    return quantidade;
}

long quantidadeDivisores(long number){
    if (number == 1)
        return 1;
    if (number <= 3)
        return 2;
    long* primos = montaPrimos(number);
    long resuldado = contaDivisores(number, primos);
    delete(primos);
    return resuldado;
}

int main(){
    const int aux = 10;
    long* primos = montaPrimos(aux);
    for(int i =0; i < aux; i++)
        std::cout << primos[i] << "\n";
    delete(primos);
    return 0;
}