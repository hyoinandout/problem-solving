#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> dice(4,std::vector<int>(3,0));

    int n,m,x,y,k;
    std::cin>>n>>m>>x>>y>>k;

    std::vector<std::vector<int>> diceMap(n,std::vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cin>>diceMap[i][j];
        }
    }

    int dy[4] = {0,0,-1,1};
    int dx[4] = {1,-1,0,0};
    for(int i=0;i<k;i++)
    {
        int cmd = 0;
        std::cin>>cmd;
        //�ֻ��� ��ġ �ű��
        x += dy[cmd-1];
        y += dx[cmd-1];
        if(x<0||x>=n||y<0||y>=m)
        {
            x -= dy[cmd-1];
            y -= dx[cmd-1];
            continue;
        }
        //�ֻ��� ������(ȸ��)
        // ��/��
        if(cmd <= 2)
        {
            //��
            if(cmd == 1)
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[1][2];
                dice[1][2] = dice[1][1];
                dice[1][1] = dice[1][0];
                dice[1][0] = tmp;
            }
            //��
            else
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[1][0];
                dice[1][0] = dice[1][1];
                dice[1][1] = dice[1][2];
                dice[1][2] = tmp;
            }
        }
        // ��/��
        else
        {
            //��
            if(cmd == 3)
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[0][1];
                dice[0][1] = dice[1][1];
                dice[1][1] = dice[2][1];
                dice[2][1] = tmp;
            }
            else
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[2][1];
                dice[2][1] = dice[1][1];
                dice[1][1] = dice[0][1];
                dice[0][1] = tmp;
            }

        }
        //�ٴ� �� ����
        if(diceMap[x][y] == 0)
        {
            diceMap[x][y] = dice[3][1];
        }
        else
        {
            dice[3][1] = diceMap[x][y];
            diceMap[x][y] = 0;
        }
        //�ֻ��� ���� �� ���
        std::cout<<dice[1][1]<<std::endl;
    }
}