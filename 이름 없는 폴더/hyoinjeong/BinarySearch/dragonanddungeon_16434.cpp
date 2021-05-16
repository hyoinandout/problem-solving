#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,t,a,h;
	long long useratk,userhp=0,minvalue=999999999;
	
	cin>>N>>useratk;
	
	for(int i=0;i<N;i++)
	{
		cin>>t>>a>>h;
		if(t==1)
		{
			if(h%useratk==0)
			{
				userhp-=a*(h/useratk-1);
			}
			else
			{
				userhp-=a*(h/useratk);
			}
		}
		else
		{
			useratk+=a;
			if(userhp+h>=0)
			{
				userhp=0;
			}
			else
			{
				userhp+=h;
			}
		}
		minvalue=min(minvalue,userhp);
	}
	cout<<-minvalue+1;
}