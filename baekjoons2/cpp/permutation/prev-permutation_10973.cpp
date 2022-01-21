#include <iostream>
#include <vector>



int main()
{
    int n;
    std::cin>>n;
    std::vector<int> permutation_array(n,0);
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        permutation_array[i] = x;
    }
    int i;
    for(i = n-1; i > 0; i--){
        if(permutation_array[i] < permutation_array[i-1])
        {
            break;
        }
    }
    if(i==0)
    {
        std::cout<<"-1\n";
    }
    else
    {
        int a = 0;
        for(int j = i; j < n; j++)
        {
            if(permutation_array[j] < permutation_array[i-1]){
                a = j;
            }
        }
        int tmp;
        tmp = permutation_array[a];
        permutation_array[a] = permutation_array[i-1];
        permutation_array[i-1] = tmp;
        for(int k = i; k < i + (n-i)/2 ; k++){
            tmp = permutation_array[k];
            permutation_array[k] = permutation_array[n-k+i-1];
            permutation_array[n-k+i-1] = tmp;
        }
        for(auto element:permutation_array)
        {
            std::cout<<element<<" ";
        }
        std::cout<<"\n";
    }
}