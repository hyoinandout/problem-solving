#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int sequence[K];
	int temp[K];
	vector<int> tab;
	vector<int>::iterator it;
	for(int i=0;i<K;i++)
	{
		cin>>sequence[i];
		temp[i]=sequence[i];
	}
	
	
	int count=0;
	for(int i=0;i<K;i++)
	{
		it=find(tab.begin(),tab.end(),sequence[i]);
		if(it==tab.end())
		{
			tab.push_back(sequence[i]);
			count++;
		}
		if(count==N)
			break;
	}
	
	int *ptr[K]={0};
	int *max;
	int cnt=0;
	for(int i=0;i<K;i++)
	{
		cout<<"i: "<<i<<endl;
		cout<<"sequence[i]: "<<sequence[i]<<endl;
		it=find(tab.begin(),tab.end(),sequence[i]);
		for(int j=0;j<N;j++)
		{
			if(it!=tab.end())
			{
				break;
			}
			else
			{
				ptr[j] = find(sequence,sequence+K,tab[j]);
			}
			cout<<"tab[j]: "<<tab[j]<<endl;
		}
		if(it==tab.end())
		{
			max = *max_element(ptr,ptr+N-1);
			*max = sequence[i];
			cnt++;
		}
		cout<<cnt<<endl;
	}
	cout<<cnt<<endl;
}
