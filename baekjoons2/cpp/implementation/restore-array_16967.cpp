// 안되는 이유: 0 들어가면?
// 따라서 범위로
#include <iostream>
#include <vector>

int main()
{
    int h,w,x,y;
    std::cin>>h>>w>>x>>y;
    std::vector<std::vector<int>> arr(h+x,std::vector<int> (w+y,0));
    for(int i=0;i<h+x;i++)
    {
        for(int j=0;j<w+y;j++)
        {
            std::cin>>arr[i][j];
        }
    }

    std::vector<std::vector<int>> restoredArr1(h,std::vector<int> (w,0));
    std::vector<std::vector<int>> restoredArr2(h,std::vector<int> (w,0));

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            restoredArr1[i][j] = arr[i][j];
            restoredArr2[i][j] = arr[i+x][j+y];
            // if(restoredArr1[i][j] != restoredArr2[i][j])
            if(i < h - x && j < w - y)
            {
                arr[i+x][j+y] = restoredArr2[i][j] - restoredArr1[i][j];
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            std::cout<<restoredArr1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}