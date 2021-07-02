#include <cstdio>
#include <algorithm>
#define MAX_NUM -1000000
using namespace std;

int arr[1001] = {0};

int main(){
	int t, result;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		result=MAX_NUM;
		for(int j=0;j<n;j++){
			int a;
			scanf("%d",&a);
			arr[j+1]=arr[j]+a;
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<=n;k++){
				result=max(result,arr[k]-arr[j]);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
