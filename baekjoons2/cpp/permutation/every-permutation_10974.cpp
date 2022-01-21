#include <iostream>
#include <vector>

bool visited[9];
std::vector<int> answer;
void fpermutation(int cnt, int n);


void permutation(int n)
{
    for(int i = 1; i < n+1; i++){
        answer.push_back(i);
        visited[i] = true;
        fpermutation(1,n);
        answer.pop_back();
        visited[i] = false;
    }

}

void fpermutation(int cnt, int n)
{
    if(cnt == n)
    {
        for(auto element: answer)
        {
            std::cout<<element<<" ";
        }
        std::cout<<'\n';
        return;
    }
    for(int i = 1; i < n+1; i++){
        if(!visited[i]){
            answer.push_back(i);
            visited[i] = true;
            fpermutation(cnt+1,n);
            answer.pop_back();
            visited[i] = false;
        }
    }    
}

int main()
{
    int n;
    std::cin>>n;
    permutation(n);
}