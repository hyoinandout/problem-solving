#include <iostream>
#include <vector>
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    std::vector<long long> results(1000001,0);
    for(int i = 1; i < 1000001; i ++){
        for(int j = 1; i * j < 1000001; j++){
            results[i*j] += i;
        }
        results[i] += results[i-1];
    }
    // for(int i = 1; i < 1000001; i++){
    // }
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin>>n;
        printf("%lld\n",results[n]);
    }
}