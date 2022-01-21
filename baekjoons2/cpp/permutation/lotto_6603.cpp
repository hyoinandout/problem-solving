#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int k = 1;
    while(1)
    {
        std::cin>>k;
        if(k == 0)
        {
            break;
        }
        std::vector<int> array;
        for(int i = 0; i < k; i++)
        {
            int x;
            std::cin>>x;   
            array.push_back(x);
        }
        
        std::vector<int> choice;
        for(int i = 0; i < 6; i++)
        {
            choice.push_back(1);            
        }
        for(int i = 0; i < k-6; i++)
        {
            choice.push_back(0);            
        }
        do
        {
            for(int i = 0; i < k; i++)
            {
                if(choice[i] == 1)
                {
                    std::cout<<array[i]<<" ";
                }
            }
            std::cout<<"\n";
        } while (std::prev_permutation(choice.begin(),choice.end()));
        std::cout<<"\n";
    }
    return 0;
}