#include <iostream>

template <typename Number>
bool isPalindrome(Number number){
    Number reversed = 0;
    while(number > reversed){
        reversed = (10*reversed) + (number % 10);
        number = number / 10;
        if(number == reversed)
            return true;
    }
    return false;
}

int main(){
    int maximo = 999;
    long maiorP = 0;
    long produto = 1;

    for(int i = maximo; i > 100; i--)
        for(int j = maximo; j >100; j--){
            produto = i * j;
            if(produto < maiorP)
                break;
            if(isPalindrome<long>(produto) && produto > maiorP)
                maiorP = produto;
        }
    std::cout << maiorP<< "\n";
    return 0;
}
