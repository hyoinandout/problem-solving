#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> divisors(n,0);
    for(int i = 0; i < n;  i++){
        std::cin>>divisors[i];
    }
    std::sort(divisors.begin(),divisors.end());
    if(!(n%2)){
        printf("%d",divisors[n/2]*divisors[n/2-1]);
    }else{
        printf("%d",divisors[n/2]*divisors[n/2]);
    }
}