#include <iostream>
#include <vector>

int n, m;
bool visited[9];
std::vector<int> combinations;

void n_m(int now){
    if(now == m){
        for(auto elements:combinations){
            std::cout<<elements<<" ";
        }
        std::cout<<'\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i]){
            continue;
        }
        combinations.push_back(i);
        visited[i] = true;
        n_m(now+1);
        combinations.pop_back();
        visited[i] = false;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin>>n>>m;
    n_m(0);
}