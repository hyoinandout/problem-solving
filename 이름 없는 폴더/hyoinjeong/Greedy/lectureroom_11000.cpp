#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<pair<int,int>> lectures;
	priority_queue<int,vector<int>,greater<int>> temp;
	int start, end;
	for(int i=0;i<N;i++)
	{
		cin>>start>>end;
		lectures.push_back(make_pair(start,end));
	}
	
	sort(lectures.begin(),lectures.end());
	temp.push(lectures[0].second);
	for(int i=1;i<N;i++)
	{
		if(temp.top()<=lectures[i].first)
		{
			temp.pop();
			temp.push(lectures[i].second);
		}
		else
		{
			temp.push(lectures[i].second);
		}
	}
	cout<<temp.size()<<endl;
}