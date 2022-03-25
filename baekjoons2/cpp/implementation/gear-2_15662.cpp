#include <stdio.h>
#include <iostream>
#include <vector>

void rotateGear(std::vector<int>& gear,int dir)
{
    if(dir == -1)
    {
        int tmp = gear[0];
        for(int i=1;i<8;i++)
        {
            gear[i-1] = gear[i];
        }
        gear[7] = tmp;
    }
    else if(dir == 1)
    {
        int tmp = gear[7];
        for(int i=7;i>0;i--)
        {
            gear[i] = gear[i-1];
        }
        gear[0] = tmp;
    }
}

int main()
{
    int t;
    std::cin>>t;
    std::vector<std::vector<int>> gears(t+1,std::vector<int>(8,0));
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<8;j++)
        {
            scanf("%1d",&gears[i][j]);
        }
    }
    
    int k;
    std::cin>>k;
    for(int i=0;i<k;i++)
    {
        int num, dir;
        std::cin>>num>>dir;
        // 3시 gears[][2], 9시 gears[][6]
        std::vector<int> howToRotate(t+1,0);
        howToRotate[num] = dir;
        // 우측부터 전파
        for(int j=num;j<t;j++)
        {
            if(gears[j][2] != gears[j+1][6])
            {
                howToRotate[j+1] = howToRotate[j] * -1;
            }
            else
            {
                break;
            }
        }
        //좌측
        for(int j=num;j>1;j--)
        {
            if(gears[j][6] != gears[j-1][2])
            {
                howToRotate[j-1] = howToRotate[j] * -1;
            }
            else
            {
                break;
            }
        }
        for(int j=1;j<=t;j++)
        {
            rotateGear(gears[j],howToRotate[j]);
            // for(int k=0;k<8;k++)
            // {
            //     std::cout<<gears[j][k];
            // }
            // std::cout<<std::endl;
        }
    }

    int cnt = 0;
    for(int i=1;i<=t;i++)
    {
        if(gears[i][0] == 1)
        {
            cnt += 1;
        }
    }
    std::cout<<cnt<<std::endl;
    return 0;
}