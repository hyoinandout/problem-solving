//dp
//문제상황에 따라 유연하게 mid부터 퍼져나가는 부분을 잘 짜야함
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
        // 반례 존재: 5 -> -1 0 5 -3 4 처럼 큰 수 뒤에 음수 장벽이 있다면?
        // 너무 히스토그램만 봤었나..
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