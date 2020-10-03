#include <iostream>

template <typename Number>
Number soma_pa(Number primeiro, Number ultimo, Number razao){
    Number resultado, quant_termos;
    quant_termos = ((ultimo - primeiro) / razao) + 1;
    resultado = ((primeiro + ultimo) * quant_termos )/(2);
    return resultado;
}

template <typename Number>
Number max_div_menorque(Number maximo, Number divisor){
    return (maximo - (maximo % divisor));
}

int main(){
    int maximo = 1000-1;
    int ultimo[3] = {maximo, max_div_menorque<int>(maximo, 5) , max_div_menorque<int>(maximo, 15)};
    int resultado = soma_pa<int>(3, ultimo[0], 3) + soma_pa<int>(5, ultimo[1], 5) - soma_pa<int>(15, ultimo[2], 15);

    std::cout << resultado << "\n";

    return 0;
}
