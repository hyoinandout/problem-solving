#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
std::vector<int> array;
std::vector<int> resultArray;

void n_m(int now){
    if(now == m){
        for(auto result : resultArray){
            std::cout<<result<<" ";
        }
        std::cout<<"\n";
        return;
    }
    for(int i = 0; i < n; i++){
        resultArray.push_back(array[i]);
        n_m(now+1);
        resultArray.pop_back();
    }
}

int main()
{
    std::cin>>n>>m;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        array.push_back(x);
    }
    std::sort(array.begin(),array.end());
    n_m(0);
}