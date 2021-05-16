//same as tile01
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int arr[1001];
	//long long으로 하고 최종결과에 나머지 하면 답이 틀렸다 나오는데 왜그럴까 -> long도 벗어나기때문에
	int sum=1;
	arr[1]=1;
	arr[2]=3;
	for(int i=3;i<=N;i++)
	{
		arr[i]=(arr[i-1]+2*arr[i-2])%10007;
		
	}
	cout<<arr[N]<<endl;
	return 0;	
}