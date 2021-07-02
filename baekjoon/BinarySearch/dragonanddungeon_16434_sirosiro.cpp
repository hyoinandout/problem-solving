#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,atk;
	cin>>n>>atk;
	
	bool room[n];
	int roomkind;
	int monatk[n];
	int monhp[n];
	long long max;
	for(int i=0;i<n;i++)
	{
		cin>>roomkind;
		room[i]=--roomkind;
		cin>>monatk[i]>>monhp[i];
		if(!room[i])
		{
			max+=monhp[i];
		}
	}
	
	//for(int i=0;i<n;i++)
	//{
	//	cout<<"i : "<<i<<endl;
	//	cout<<"roomkind : "<<room[i]<<" monatk[i] : "<<monatk[i]<<" monhp[i] : "<<monhp[i]<<endl;
	//}
	
	//cout<<"max : "<<max<<endl;
	
	
	
	
	
	
	
	
	long long low=1,high=50;
	while(low<=high)
	{
		//bool clear=false;
		
		int mid=(low+high)/2;
		int maxhp=mid;
		int cnt=0;
		int tempatk=atk;
		cout<<"mid : "<<mid<<endl;
		for(int i=0;i<n;i++)
		{
			int tempmonhp=monhp[i];
			cout<<"room[i] : "<<room[i]<<endl;
			if(room[i])
			{
				if(maxhp>=monhp[i])
				{
					maxhp=mid;
				}
				else
				{
					maxhp+=monhp[i];
				}
				tempatk+=monatk[i];
				cnt++;
			}
			else
			{
				while((tempmonhp>tempatk)&&(monatk[i]<maxhp))
				{
					tempmonhp-=tempatk;
					// if(monhp[i]<=0)
					// {
					// 	//clear=true;
					// 	break;
					// }  
					maxhp-=monatk[i];
					// if(maxhp<=0)
					// {
					// 	break;
					// }
					cout<<"i : "<<i<<endl;
					cout<<"monhp[i] : "<<monhp[i]<<endl;
					cout<<"tempmonhp : "<<tempmonhp<<endl;
					cout<<"maxhp : "<<maxhp<<endl;
				}
				if(maxhp>monatk[i])
					cnt++;
			}
			// if(clear)
			// 	continue;
			// else
			// 	break;
		}
		cout<<"cnt : "<<cnt<<endl;
		if(cnt<n)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<low<<endl;
}