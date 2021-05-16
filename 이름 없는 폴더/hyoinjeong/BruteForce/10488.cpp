#include <iostream>
using namespace std;

bool func(int num)
{
	int arr[334]={0};
	int i=0;
	do
	{
		arr[i]=((i+1)*(i+2))/2;
		i++;
	}while(arr[i]<334);
	for(int i=0;i<334;i++)
	{
		for(int j=0;j<334;j++)
		{
			for(int k=0;k<334;k++)
			{
				if((arr[i]+arr[j]+arr[k])==num)
					return 1;
			}
		}
	}
	return 0;
}






int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<func(arr[i])<<endl;
	}
}