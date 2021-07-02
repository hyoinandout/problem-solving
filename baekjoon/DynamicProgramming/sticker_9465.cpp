#include <cstdio>
#include <algorithm>


int arr[2][100000];
int dp[100000][3];
int n;
int sticker(int i, int stat) // 직전에 1이면 아래, 0이면 안뗌, 2이면 위
{
	if(i==n) return 0;
	if(dp[i][stat]!=-1) return dp[i][stat];	
	int result = sticker(i+1,0);
	if(stat!=1) result=std::max(result,sticker(i+1,1)+arr[0][i]);
	if(stat!=2) result=std::max(result,sticker(i+1,2)+arr[1][i]);
	dp[i][stat] = result;
	return result;
}

int main()
{
	int T;
	scanf("%d",&T);
	
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<n;k++)
			{
				scanf("%d",&arr[j][k]);
			}
		}
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<3;y++)
			{
				dp[x][y]=-1;
			}
		}
		printf("%d\n",sticker(0,0));
	}
	return 0;	
}