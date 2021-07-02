#include <bits/stdc++.h>

using namespace std;
int main()
{
	int N,C;
	cin>>N>>C;
	int pos[N];
	for(int i=0;i<N;i++)
	{
		cin>>pos[i];
	}
	
	sort(pos,pos+N);
	
	int low=0, high=1000000000;
	int answer=-1;
	while(low<=high)
	{
		long long mid=(low+high)/2;
		int index = 0;
		long long  cnt = 1;
		for(int i=1;i<N;i++)
		{
			// cout<<endl;
			// cout<<"mid : "<<mid<<endl;
			// cout<<"i : "<<i<<endl;
			// cout<<"pos[i] : "<<pos[i]<<endl;
			// cout<<"index : "<<index<<endl;
			// cout<<"pos[index] : "<<pos[index]<<endl;
			if(pos[i]>=pos[index]+mid)
			{
				cnt++;
				index=i;
			}
		}
		// cout<<"cnt : "<<cnt<<endl;
		if(cnt>=C)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
		
		if(answer<mid && cnt>=C)
		{
			answer=mid;
		}
	
	}
	cout<<answer;
}