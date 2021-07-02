#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> H;
vector<long long> sum;

long long func(int s, int e)
{
	if(s==e)
	{
		return 0;
	}
	if(s+1==e)
	{
		return (sum[s]-sum[s-1])*H[s];
	}
	
	int mid = (s+e)/2;
	long long result = max(func(s,mid),func(mid,e));
	
	int h=H[mid], l=mid, r=mid;
	while(r-l+1<e-s)
	{
		int p = s<l?min(h,H[l-1]):-1;
		int q = r<e-1?min(h,H[r+1]):-1;
		if(p>=q)
		{
			h=p;
			l--;
		}
		else
		{
			h=q;
			r++;
		}
		result = max((long long)result,(sum[r]-sum[l-1])*h);
	}
	
	return result;
}


int main()
{
	
	cin>>N;
	H.assign(N+1,0);
	sum.assign(N+1,0);
	long long s=0;
	for(int i=1;i<=N;i++)
	{
		cin>>H[i];
		s+=H[i];
		sum[i]=s;
	}
	
	cout<<func(1,N+1)<<endl;
	return 0;
}