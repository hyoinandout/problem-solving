#include <iostream>
#include <string>
#include <queue>

int main()
{
    int n;
    std::cin>>n;
    std::queue<int> q;
    for(int i = 0; i < n; i++)
    {
        std::string a;
        std::cin>>a;
        if(a == "push")
        {
            int n;
            std::cin>>n;
            q.push(n);
        }
        else if(a == "front")
        {
            if(q.empty())
            {
                std::cout<<"-1"<<std::endl;
            }
            else
            {
                std::cout<<q.front()<<std::endl;
            }
        }
        else if(a == "back")
        {
            if(q.empty())
            {
                std::cout<<"-1"<<std::endl;
            }
            else
            {
                std::cout<<q.back()<<std::endl;
            }
        }
        else if(a == "size")
        {
            std::cout<<q.size()<<std::endl;
        }
        else if(a == "empty")
        {
            if(q.empty())
            {
                std::cout<<1<<std::endl;
            }
            else
            {
                std::cout<<0<<std::endl;
            }
        }
        else if(a == "pop")
        {
            if(q.empty())
            {
                std::cout<<"-1"<<std::endl;
            }
            else
            {
                int x = q.front();
                q.pop();
                std::cout<<x<<std::endl;
            }
        }
    }
    return 0;
}