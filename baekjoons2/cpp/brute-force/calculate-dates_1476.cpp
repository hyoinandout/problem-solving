#include <iostream>

int main()
{
    int e,s,m;
    std::cin>>e>>s>>m;
    long long x = 0;
    while(1){
        long long year = 15 * x + (e-1);
        if((year % 28 == (s-1))&&(year % 19 == (m-1))){
            printf("%lld",year+1);
            break;
        }
        x += 1;
    }
}