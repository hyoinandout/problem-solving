#include <iostream>
#include <cmath>

bool primes[1000001];
void checkPrimes(){
    primes[1] = true;
    int k = sqrt(1000001);
    for(int i = 2; i <= k; i++){
        for(int j = 2; i * j <= 1000001; j++){
            primes[i*j] = true;
        }
    }
}


int main(){
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n;
    checkPrimes();
    while(1){
        std::cin>>n;
        if(n==0){
            break;
        }
        bool flag = false;
        for(int i = 2; i < n; i++){
            if(!primes[i]){
                if(!primes[n-i]){
                    printf("%d = %d + %d\n",n,i,n-i);
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}