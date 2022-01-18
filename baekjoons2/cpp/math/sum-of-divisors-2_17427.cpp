#include <iostream>
// 10 =
// 1
// 1 2
// 1 3
// 1 2 4
// 1 5
// 1 2 3 6
// 1 7
// 1 2 4 8
// 1 3 9
// 1 2 5 10

int main(){
    int n;
    long long sum = 0;
    std::cin>>n;
    for(int i = 1; i <= n; i++){
        sum += i * (n / i);
    }
    std::cout<<sum<<std::endl;
}