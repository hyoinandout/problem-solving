#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;

    std::vector<int> arr(n,0);
    std::vector<int> idp(n,1);
    std::vector<int> ddp(n,1);

    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        arr[i] = x;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                idp[i] = std::max(idp[i],idp[j]+1);
            }
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j])
            {
                ddp[i] = std::max(ddp[i],ddp[j]+1);
            }
        }
    }

    int result = 0;
    for(int i=0;i<n;i++)
    {
        result=std::max(result,ddp[i]+idp[i]-1);
    }
    std::cout<<result<<"\n";
    return 0;
}