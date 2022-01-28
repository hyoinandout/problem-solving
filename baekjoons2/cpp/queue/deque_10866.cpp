#include <iostream>
#include <string>
#include <deque>

int main()
{
    int n;
    std::cin>>n;
    std::deque<int> dq;
    for(int i=0;i<n;i++)
    {
        std::string s;
        std::cin>>s;
        int x;
        if(s == "push_back")
        {
            std::cin>>x;
            dq.push_back(x);
        }
        else if(s == "push_front")
        {
            std::cin>>x;
            dq.push_front(x);
        }
        else if(s == "pop_front")
        {
            if(dq.empty())
            {
                std::cout<<-1<<std::endl;
            }
            else
            {
                int a = dq.front();
                dq.pop_front();
                std::cout<<a<<std::endl;
            }
        }
        else if(s == "pop_back")
        {
            if(dq.empty())
            {
                std::cout<<-1<<std::endl;
            }
            else
            {
                int a= dq.back();
                dq.pop_back();
                std::cout<<a<<std::endl;
            }
        }
        else if(s == "size")
        {
            std::cout<<dq.size()<<std::endl;
        }
        else if(s == "empty")
        {
            std::cout<<dq.empty()<<std::endl;
        }
        else if(s == "front")
        {
            if(dq.empty())
            {
                std::cout<<-1<<std::endl;
            }
            else
            {
                std::cout<<dq.front()<<std::endl;
            }
        }
        else if(s == "back")
        {
            if(dq.empty())
            {
                std::cout<<-1<<std::endl;
            }
            else
            {
                std::cout<<dq.back()<<std::endl;
            }

        }
    }
}