#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<pair<int,int>> lectures;
	vector<pair<int,int>> temp;
	int start, end;
	for(int i=0;i<N;i++)
	{
		cin>>start>>end;
		lectures.push_back(make_pair(start,end));
	}
	
	sort(lectures.begin(),lectures.end());
	int i,j=0;
	bool used;
	for(i=0;i<N;i++)
	{
		used = 0;
		for(j=0;j<temp.size();j++)
		{
			if(temp[j].second<=lectures[i].first)
			{
				temp[j]=lectures[i];
				used =1;
				break;
			}
		}
		if(!used)
		{
			temp.push_back(lectures[i]);
		}
	}
	cout<<temp.size()<<endl;
}