#include <bits/stdc++.h>

using namespace std;

char arr[3000][3000];

void init()
{
	for(int i=0;i<3000;i++)
	{
		for(int j=0;j<3000;j++)
		{
			arr[i][j]=' ';
		}
	}
}

void star(int i, int j ,int n)
{
	if(n==1)
	{	
		arr[i][j]='*';
		return;
	}
	int div=n/3;
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++)
		{
			if((x==1)&&(y==1))
			{
				continue;
			}
			star(i+(x*div),j+(y*div),div);
		}
	}
}

int main()
{
	int N;
	cin>>N;
	init();
	star(0,0,N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}