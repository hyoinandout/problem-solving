#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, L;
	cin>>N>>L;
	int spoil[N];
	for(int i=0;i<N;i++)
	{
		cin>>spoil[i];
	}
	int count=0;
	int i,j;
	sort(spoil,spoil+N);
	for(i=0;i<N-1;i=j)
	{
		for(j=i+1;j<N;j++)
		{
			if(spoil[j]>spoil[i]+L-1)
			{
				count++;
				break;
			}
		}
	}
	cout<<++count<<endl;
	
}