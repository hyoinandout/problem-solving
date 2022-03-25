#include <iostream>
#include <vector>
#include <cstring>
int n,l;

int leftRightSlope(std::vector<std::vector<int>> heightMap)
{
    int result = 0;
    //�� -> �� / �� -> �� Ž���ϸ鼭 ���� ��ġ �����ϴٸ� ��ġ. �� �� �� -> �� ���鼭 ���� 1���� �� �� �� �� ����, �ƴҽ� break
    for(int i=0;i<n;i++)
    {
        //�˰��� �� ���̰� ��ġ�� ���(ex n=5,l=2,heightMap[0] = 32223) �� ���� ����� ���� isBuilt �迭 ����) + ���� ���� ���ΰ� ������ �´� �����ΰ�? : ��->�� ���� 0�� ������, 1�� ������
        bool isBuilt[n][2];
        memset(isBuilt,false,sizeof(isBuilt));
        // �� -> �� Ž��
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
        // �� -> �� Ž��
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
        // �� ����
        
        // Built Ȯ��
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
    // leftRightSlope�� ���� ����
    for(int i=0;i<n;i++)
    {
        bool isBuilt[n][2];
        memset(isBuilt,false,sizeof(isBuilt));
        // �� -> �� Ž��
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
        // �� -> �� Ž��
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
        // �� ����
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