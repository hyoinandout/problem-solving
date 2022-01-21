#include <iostream>
#include <vector>
#include <algorithm>
int n;

int main(){
    std::cin>>n;
    std::vector<int> permutation(n,0);
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        permutation[i] = x;
    }
    int j = n-1;
    while(j>0){
        if(permutation[j] > permutation[j-1]){
            break;
        }
        j -= 1;
    }
    if(j == 0){
        std::cout<<"-1"<<'\n';
    } else{
        if(j == n-1){
            int tmp = permutation[j-1];
            permutation[j-1] = permutation[j];
            permutation[j] = tmp;
        }else{
            int nearNum = 10000;
            int x = 0;
            for(int i = j; i < n; i++){
                if(permutation[i] - permutation[j-1] < nearNum && permutation[i] - permutation[j-1] > 0){
                    nearNum = permutation[i] - permutation[j-1];
                    x = i;
                }
            }
            int tmp = permutation[j-1];
            permutation[j-1] = permutation[x];
            permutation[x] = tmp;
            std::sort(permutation.begin()+j, permutation.end());
        }
        for(auto element: permutation){
            std::cout<<element<<" ";
        }
    }
}