#include <iostream>
using namespace std;

int N;
bool arr[100][100];
bool check[100];

void dfs(int curr,int n){
	for(int i=0;i<n;i++){
		if(arr[curr][i]&&!check[i]){
			check[i]=1;
			dfs(i,n);
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<N;i++){
		dfs(i,N);
		for(int j=0;j<N;j++){
			arr[i][j]=check[j];
			check[j]=0;
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}