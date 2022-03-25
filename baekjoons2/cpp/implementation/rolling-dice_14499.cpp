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
        //주사위 위치 옮기기
        x += dy[cmd-1];
        y += dx[cmd-1];
        if(x<0||x>=n||y<0||y>=m)
        {
            x -= dy[cmd-1];
            y -= dx[cmd-1];
            continue;
        }
        //주사위 굴리기(회전)
        // 동/서
        if(cmd <= 2)
        {
            //동
            if(cmd == 1)
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[1][2];
                dice[1][2] = dice[1][1];
                dice[1][1] = dice[1][0];
                dice[1][0] = tmp;
            }
            //서
            else
            {
                int tmp = dice[3][1];
                dice[3][1] = dice[1][0];
                dice[1][0] = dice[1][1];
                dice[1][1] = dice[1][2];
                dice[1][2] = tmp;
            }
        }
        // 남/북
        else
        {
            //북
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
        //바닥 값 복사
        if(diceMap[x][y] == 0)
        {
            diceMap[x][y] = dice[3][1];
        }
        else
        {
            dice[3][1] = diceMap[x][y];
            diceMap[x][y] = 0;
        }
        //주사위 윗면 값 출력
        std::cout<<dice[1][1]<<std::endl;
    }
}