#include <iostream>
#include <vector>
int n,m;
std::vector<int> combinations_with_iteration;
void n_m(int now)
{
    if(now == m){
        for(auto elements : combinations_with_iteration){
            std::cout<<elements<<" ";
        }
        std::cout<<"\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        combinations_with_iteration.push_back(i);
        n_m(now+1);
        combinations_with_iteration.pop_back();
    }
}


int main()
{
    std::cin>>n>>m;
    n_m(0);
}