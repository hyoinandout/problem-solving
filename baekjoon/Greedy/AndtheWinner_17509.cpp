#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> T;
	int t;
	int v;
	int sum = 0;
	int timesum=0;
	for(int i=0;i<11;i++)
	{
		cin>>t>>v;
		T.push_back(t);
		sum+=20*v;
	}
	sort(T.begin(),T.end());   
	for(int i=0;i<T.size();i++)
	{
		timesum += T[i];
		sum += timesum;
	}
	cout<<sum<<endl;
}