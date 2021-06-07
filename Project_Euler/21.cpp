#include <iostream>
#include <assert.h>

long solution(int const max){
    long sieve[max+1] = {0};
    for(auto i = 1; i <= max; i++)
        for(auto j = 2*i; j <= max; j+= i)
            sieve[j] += i;

    long sum = 0;
    for(auto i = 1; i <= max; i++)
        if(sieve[i] < max && sieve[sieve[i]] == i && sieve[i] != i )
            sum+= i;

    return sum;
}


int main(){
    assert(solution(300) == 504);
    std::cout << solution(10000) << "\n";
    return 0;
}
