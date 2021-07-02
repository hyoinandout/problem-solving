//다세니까 메모리초과
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int k;
	cin>>n>>k;
	//vector<long long> arr(n*n);
	
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		arr.push_back(i*j);
	// 	}
	// }
	
	int begin =1, end=k;
	//ret =-1;
	while(begin<=end)
	{
		int mid = (begin+end)/2;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=min(mid/i,n);
			// if(arr[i]<=mid)
			// {
			// 	cnt++;
			// }
		}
		if(cnt<k)
		{
			begin=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	cout<<begin<<endl;
}