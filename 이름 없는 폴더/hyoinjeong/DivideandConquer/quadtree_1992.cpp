#include <bits/stdc++.h>

using namespace std;

char arr[64][64];

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
void quadtree(int i, int j ,int n)
{
	
	if(same(i,j,n))
	{
		cout<<arr[i][j];
		return;
	}
	cout<<"(";
	int div=n/2;
	for(int x=0;x<2;x++)
	{
		for(int y=0;y<2;y++)
		{
			quadtree(i+(x*div),j+(y*div),div);
		}
	}
	cout<<")";
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf(" %c",&arr[i][j]);
		}
	}
	quadtree(0,0,N);
	return 0;
}