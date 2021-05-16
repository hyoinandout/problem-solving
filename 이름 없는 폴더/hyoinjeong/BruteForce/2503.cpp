#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char num[n][4];
	int strike[n],ball[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		cin>>strike[i];
		cin>>ball[i];
	}
	
	vector<string> answers;
	int x,y,z;
	for(int i=123;i<988;i++)
	{
		string k = to_string(i);
		if(k.find('0')==-1)
		{
			if((k[0]!=k[1])&&(k[0]!=k[2])&&(k[1]!=k[2]))
			{
				answers.push_back(k);
			}
		}
	}
	
	int count=0;
	int fakestrike[n]={0};
	int fakeball[n]={0};
	for(int i=0;i<answers.size();i++)
	{
		bool pandog = 1;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(strchr(num[j],answers[i][k])!=NULL)// 123에서 123이 있는가?
				{
					if((answers[i][k])==(num[j][k]))
					{
						fakestrike[j]++;
					}
					else
					{
						fakeball[j]++;
					}
				}
			}//여기서 123 입력값일때 1S 1B
			if((fakestrike[j]==strike[j])&&(fakeball[j]==ball[j]))
			{
				pandog *= 1;
			}
			else
			{
				pandog *= 0;
			}
			fakestrike[j]=0;
			fakeball[j]=0;
		}
		if(pandog)
		{
			count++;
		}
	}
	
	cout<<count<<endl;
	return 0;
}
//한번 입력할때마다
