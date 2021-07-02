#include <iostream>

using namespace std;

int func(int* arr,int i,int s,bool ox)
{
	cout<<arr[i]<<" "<<i<<" "<<s<<" "<<ox<<endl;
	int answer=0;
	int count[2];
	int size=sizeof(arr)/sizeof(arr[0]);
	if(i==size)
	{
		return 0;
	}
	if(!ox)
	{
		count[0]= func(arr,i+1,s,0);
		cout<<count[0]<<endl;
		count[1]= func(arr,i+1,s,1);
	}
	else
	{
		count[0]= arr[i] + func(arr,i+1,s,0);
		count[1]= arr[i] + func(arr,i+1,s,1);
	}
	cout<<"count[0] : "<<count[0]<<" count[1] : "<<count[1]<<endl;
	if((count[0]==s)||(count[1]==s))
	{
		answer++;
	}
	return answer;
}

int main()
{
	int N,S;
	cin>>N;//3
	cin>>S;//3
	int numbers[N]={0};
	for(int i=0;i<N;i++)
	{
		cin>>numbers[i];//1,2,3
	}
	int count1 = 0;
	count1=func(numbers,0,S,0);//1 2 3,0,3,0
	int count2 = 0;
	count2=func(numbers,0,S,1);//1 2 3,0,3,0
	cout<<count1+count2<<endl;
	return 0;
}