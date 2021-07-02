#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<pair<int,int>> conferences;
	int start,end;
	for(int i=0;i<N;i++)
	{
		cin>>start>>end;
		conferences.push_back(make_pair(start,end));
	}
	sort(conferences.begin(),conferences.end());
	int count = 1;
	int tempstart=0, tempend=INT_MAX;
	int i=0;
	do
	{
		if(tempend<=conferences[i].first)
		{
			count++;
			tempstart = conferences[i].first;
			tempend= conferences[i].second;
		}
		else if((conferences[i].first>=tempstart)&&(conferences[i].second<=tempend))
		   {
			   tempstart = conferences[i].first;
			   tempend= conferences[i].second;
		   }
		
		
		// cout<<"start: "<<tempstart<<endl;
		// cout<<"end: "<<tempend<<endl;
		// cout<<"count: "<<count<<endl;
		i++;
	}while(i<conferences.size());
	cout<<count<<endl;
}