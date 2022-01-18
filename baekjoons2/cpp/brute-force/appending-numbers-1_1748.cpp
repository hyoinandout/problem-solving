#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    int sum = n;
    int sub = 9;
    while(n-sub>0){
        sum += (n - sub);
        sub = (sub * 10 + 9);
    }
    std::cout<<sum<<std::endl;
}