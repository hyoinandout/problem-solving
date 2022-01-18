#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
std::vector<int> array;
std::vector<int> resultArray;
bool visited[9];

void n_m(int now){
    if(now == m){
        for(auto elements: resultArray){
            std::cout<<elements<<" ";
        }
        std::cout<<"\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[i])
            continue;
        resultArray.push_back(array[i]);
        visited[i] = true;
        n_m(now+1);
        resultArray.pop_back();
        visited[i] = false;
    }

}

int main(){
    std::cin>>n>>m;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        array.push_back(x);
    }
    std::sort(array.begin(),array.end());
    n_m(0);
}