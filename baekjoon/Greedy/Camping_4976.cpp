#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	int L,P,V;
	vector<int> answer;
	
	while(1)
	{
		cin>>L>>P>>V;
		if(V==0)
			break;
		if(V%P<L)
			answer.push_back((V/P)*L+V%P);
		else
			answer.push_back((V/P)*L+L);
	}
	for(int i=0;i<answer.size();i++)
	{
		cout<<"Case "<<i+1<<": "<<answer[i]<<endl;
	}
	return 0;
}