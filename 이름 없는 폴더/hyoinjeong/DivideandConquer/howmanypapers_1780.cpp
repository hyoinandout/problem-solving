#include <bits/stdc++.h>

using namespace std;

int arr[3000][3000];
int cnt[3];

bool same(int x, int y, int n)
{
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[x][y]!=arr[i][j])
				return false;
		}
	}
	return true;
}
void paper(int i, int j ,int n)
{
	if(same(i,j,n))
	{
		cnt[arr[i][j]+1]++;
		return;
	}
	
	int div=n/3;
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++)
		{
			paper(i+(x*div),j+(y*div),div);
		}
	}
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}
	paper(0,0,N);
	cout<<cnt[0]<<endl;
	cout<<cnt[1]<<endl;
	cout<<cnt[2]<<endl;
	return 0;
}