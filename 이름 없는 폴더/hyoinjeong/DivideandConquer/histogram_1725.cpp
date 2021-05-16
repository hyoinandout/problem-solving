#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> H;

long long func(int s, int e)
{
	if(s==e)
	{
		return 0;
	}
	if(s+1==e)
	{
		return H[s];
	}
	
	int mid = (s+e)/2;
	long long result = max(func(s,mid),func(mid,e));
	
	int w=1, h=H[mid], l=mid, r=mid;
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
		result = max((long long)result,(long long)++w*h);
	}
	
	return result;
}


int main()
{
	
	cin>>N;
	H.assign(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>H[i];
	}
	
	cout<<func(0,N)<<endl;
	return 0;
}