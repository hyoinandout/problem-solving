#include <iostream>
#include <vector>
#include <cstring>
int n,l;

int leftRightSlope(std::vector<std::vector<int>> heightMap)
{
    int result = 0;
    //서 -> 동 / 동 -> 서 탐색하면서 경사로 설치 가능하다면 설치. 그 후 서 -> 동 가면서 높이 1차이 날 시 갈 수 있음, 아닐시 break
    for(int i=0;i<n;i++)
    {
        //알고리즘 상 길이가 겹치는 경우(ex n=5,l=2,heightMap[0] = 32223) 에 대한 계산을 위해 isBuilt 배열 생성) + 내가 가는 경사로가 방향이 맞는 경사로인가? : 서->동 기준 0이 오르막, 1이 내리막
        bool isBuilt[n][2];
        memset(isBuilt,false,sizeof(isBuilt));
        // 서 -> 동 탐색
        for(int j=0;j<n-l;j++)
        {
            if(heightMap[i][j] + l == heightMap[i][j+l])
            {
                for(int k=0;k<l;k++)
                {
                    heightMap[i][j+k]+=k;
                    isBuilt[j+k][0] = true;
                }
            }
        }
        // 동 -> 서 탐색
        for(int j=n-1;j>=l;j--)
        {
            if((heightMap[i][j] + l == heightMap[i][j-l]) && !isBuilt[j][0])
            {
                for(int k=0;k<l;k++)
                {
                    heightMap[i][j-k]+=k;
                    isBuilt[j-k][1]= true;
                }
            }
        }
        // 길 세기
        
        // Built 확인
        // std::cout<<"i: "<<i<<std::endl;
        // for(int k = 0; k < n; k++)
        // {
        //     std::cout<<"isBuilt[j][0]"<<isBuilt[k][0]<<" ";
        // }
        // std::cout<<std::endl;
        // for(int k = 0; k < n; k++)
        // {
        //     std::cout<<"isBuilt[j][1]"<<isBuilt[k][1]<<" ";
        // }
        // std::cout<<std::endl;

        bool flag = true;
        for(int j=0;j<n-1;j++)
        {
            if(abs(heightMap[i][j] - heightMap[i][j+1]) > 1)
            {
                flag = false;
                break;
            }
            else if(heightMap[i][j] - heightMap[i][j+1] == 1 && !isBuilt[j+1][1])
            {
                flag = false;
                break;
            }
            else if(heightMap[i][j] - heightMap[i][j+1] == -1 && !isBuilt[j][0])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            //std::cout<<i<<std::endl;
            result += 1;
        }
    }
    return result;
}

int upDownSlope(std::vector<std::vector<int>> heightMap)
{
    int result = 0;
    // leftRightSlope와 같은 원리
    for(int i=0;i<n;i++)
    {
        bool isBuilt[n][2];
        memset(isBuilt,false,sizeof(isBuilt));
        // 북 -> 남 탐색
        for(int j=0;j<n-l;j++)
        {
            if(heightMap[j][i] + l == heightMap[j+l][i])
            {
                for(int k=0;k<l;k++)
                {
                    heightMap[j+k][i]+=k;
                    isBuilt[j+k][0] = true;
                }
            }
        }
        // 남 -> 북 탐색
        for(int j=n-1;j>=l;j--)
        {
            if((heightMap[j][i] + l == heightMap[j-l][i]) && !isBuilt[j][0])
            {
                for(int k=0;k<l;k++)
                {
                    heightMap[j-k][i]+=k;
                    isBuilt[j-k][1] = true;
                }
            }
        }
        // 길 세기
        bool flag = true;
        for(int j=0;j<n-1;j++)
        {
            if(abs(heightMap[j][i] - heightMap[j+1][i]) > 1)
            {
                flag = false;
                break;
            }
            else if(heightMap[j][i] - heightMap[j+1][i] == 1 && !isBuilt[j+1][1])
            {
                flag = false;
                break;
            }
            else if(heightMap[j][i] - heightMap[j+1][i] == -1 && !isBuilt[j][0])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            result += 1;
        }
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> heightMap(100,std::vector<int>(100,0));

    std::cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>heightMap[i][j];
            heightMap[i][j] *= l;
        }
    }
    
    int result = 0;
    result += leftRightSlope(heightMap);
    result += upDownSlope(heightMap);
    std::cout<<result<<std::endl;
    return 0;
}