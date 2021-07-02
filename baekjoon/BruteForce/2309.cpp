#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> height;
	int total=0, j, k;
	for(int i=0;i<9;i++)
	{
		int x;
		cin>>x;
		height.push_back(x);
		total+=x;
	}
	//cout<<total<<endl;
	for(j=0;j<8;j++)
	{
		for(k=j+1;k<9;k++)
		{
			if((total-height[j]-height[k])==100)
			{
				height.erase(height.begin()+k);
				height.erase(height.begin()+j);
			}
		}
	}
	sort(height.begin(),height.end());
	for(int i=0;i<7;i++)
	{
		cout<<height[i]<<endl;
	}
	
	return 0;
}