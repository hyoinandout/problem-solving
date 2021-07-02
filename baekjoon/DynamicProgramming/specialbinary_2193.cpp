#include <iostream>

using namespace std;

// pinary(N, digit) = 길이가 N이고 첫 자리가 digit인 이친수의 개수

// 풀어야 할 문제는 pinary(N, 0)이고,

// 첫 자릿수가 1인 경우 바로 다음 자릿수는 반드시 0이어야 하므로

// pinary(N, 1) = pinary(N-1, 0)

// 첫 자릿수가 0인 경우 그 다음 자릿수가 0이거나 1일 수 있으므로

// pinary(N, 0) = pinary(N-1, 0) + pinary(N-1, 1)

// -->> pinary(N,1)을 구하는건데, 이것은 사실상 pinary(N-1,0)이고, pinary(N-1,0)=pinary(N-2,0)+pinary(N-3,0)이 된다.

int main()
{
	int N;
	cin>>N;
	long long arr[N+1];
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<=N;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	cout<<arr[N]<<endl;
	return 0;
}