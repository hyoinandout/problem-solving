//dp
//������Ȳ�� ���� �����ϰ� mid���� ���������� �κ��� �� ¥����
#include <iostream>
#include <vector>
#include <algorithm>

int bs(std::vector<int>& array, int start, int end)
{
    if(start >= end)
    {
        return array[start];
    }
    int mid = (start + end) / 2;
    int left = bs(array,start,mid);
    int right = bs(array,mid+1,end);
    
    int answer = std::max(left,right);
    
    int dl = -1;
    int dr = 2;
    int midSum = array[mid];
    answer = std::max(answer,midSum);
    // while(mid + dl >= start && mid + dr <= end)
    // {
        // �ݷ� ����: 5 -> -1 0 5 -3 4 ó�� ū �� �ڿ� ���� �庮�� �ִٸ�?
        // �ʹ� ������׷��� �þ���..
    //     if(array[mid+dl] >  array[mid+dr])
    //     {
    //         midSum += array[mid+dl];
    //         dl -= 1;
    //     }
    //     else
    //     {
    //         midSum += array[mid+dr];
    //         dr += 1;
    //     }
    //     answer = std::max(answer,midSum);
    // }
    int leftMax = -1e9;
    int rightMax = -1e9;
    leftMax = std::max(leftMax,midSum);
    while(mid + dl >= start)
    {
        midSum += array[mid+dl];
        dl -= 1;
        leftMax = std::max(leftMax,midSum);
    }
    midSum = array[mid+1];
    rightMax = std::max(rightMax,midSum);
    while(mid + dr <= end)
    {
        midSum += array[mid+dr];
        dr += 1;
        rightMax = std::max(rightMax,midSum);
    }
    answer = std::max(answer,leftMax+rightMax);
    // std::cout<<start<<" "<<end<<std::endl;
    // std::cout<<answer<<std::endl;
    return answer;
}

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> array;
    for(int i = 0; i < n; i++)
    {
        int x;
        std::cin>>x;
        array.push_back(x);
    }
    std::cout<<bs(array,0,n-1)<<"\n";
    return 0;
}