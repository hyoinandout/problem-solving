#include <bits/stdc++.h>
using namespace std;

int cnt, r, c;

bool inrange(int x, int y, int n)
{
	if((x<=r)&&(r<x+n)&&(y<=c)&&(c<y+n))
	{
		return true;
	}
	return false;
}

void z(int i, int j ,int n)
{
	//cout<<"i: "<<i<<"  j: "<<j<<"  n: "<<n<<endl;
	if(!inrange(i,j,n))
	{
		cnt = cnt + n*n; 
		//cout<<"cnt :"<<cnt<<endl;
		return;
	}
	if((i==r)&&(j==c)&&(n==1))
	{
		cout<<cnt;
		return;
	}
	int div=n/2;
	for(int x=0;x<2;x++)
	{
		for(int y=0;y<2;y++)
		{
			z(i+(x*div),j+(y*div),div);
		}
	}
}

int main()
{
	int N;
	cin>>N>>r>>c;
	z(0,0,(int)pow(2,N));
	return 0;
}