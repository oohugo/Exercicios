#include <iostream>

template<typename Number>
struct trio{
    Number a;
    Number b;
    Number c;
};

trio<int> special_pythagorean_triplet(long max){
    for(int m = 4; m < max; m++)
        for(int n = 3;n < m; n++)
            if(m * (m+n) == (max/2)){
                trio<int> resut;
                resut.a = 2*m*n;
                resut.b = m*m - n*n;
                resut.c = m*m + n*n;
                return resut;
            }
    return trio<int> {0,0,0};
}


int main(){
    long long product=1;
    long max = 1000;

    trio<int> resposta = special_pythagorean_triplet(max);
    product = resposta.a * resposta.b * resposta.c;

    std::cout << product<< "\n";
    return 0;
}
