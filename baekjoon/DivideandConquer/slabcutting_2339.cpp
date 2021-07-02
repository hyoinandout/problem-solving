#include <bits/stdc++.h>

using namespace std;

int arr[20][20];
int N;

bool okdivide(int s, int e, int fix, int dir)
{
	if(dir==0)
	{
		for(int k=s;k<=e;k++)
		{
			if(arr[fix][k]==2)
			{
				return false;
			}
		}
	}
	else
	{
		for(int k=s;k<=e;k++)
		{
			if(arr[k][fix]==2)
			{
				return false;
			}
		}
	}
	return true;
}
int slabcutting(int si, int sj, int ei, int ej, int dir)
{
	int cnt[3] = {0, };
	
	for(int i=si;i<=ei;i++)
	{
		for(int j=sj;j<=ej;j++)
		{
			++cnt[arr[i][j]];
		}
	}
	if(cnt[2]==1 && cnt[1]==0) return 1;
	if(cnt[2]==0) return 0;
	
	int temp = 0;
	for(int i=si;i<=ei;i++)
	{
		for(int j=sj;j<=ej;j++)
		{
			if(arr[i][j]==1)
			{
				if(dir==0&&okdivide(sj,ej,i,dir))
				{
					temp += slabcutting(si,sj,i-1,ej,1)* slabcutting(i+1,sj,ei,ej,1);
				}
				else if(dir==1&&okdivide(si,ei,j,dir))
				{
					temp += slabcutting(si,sj,ei,j-1,0)* slabcutting(si,j+1,ei,ej,0);
				}
				
			}
			
		}
	}
	return temp;
}






int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}
	int answer = slabcutting(0,0,N-1,N-1,0)+slabcutting(0,0,N-1,N-1,1);
	cout<<((answer==0)?-1:answer)<<endl;
	return 0;
}