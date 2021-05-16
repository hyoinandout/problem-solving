#include <bits/stdc++.h>

using namespace std;

int m,n,k,xf,yf,xs,ys;
int arr[100][100]={0};
int arrx[4]={0,0,-1,1};
int arry[4]={-1,1,0,0};
bool visited[100][100];

void dfs(int x, int y){
	visited[x][y]=true;
	//크기도 여기서 구할 수 있었음.
	for(int i=0;i<4;i++){
		int xi=x+arrx[i];
		int yi=y+arry[i];
		if(xi<0||yi<0||xi>=n||yi>=m) continue;
		if(arr[x][y]==arr[xi][yi]&&!visited[xi][yi])//0에서 진입한다 해도 -1 고려했어야함.
			dfs(xi,yi);
	}
}

int main(){
	cin>>m>>n>>k;
	for(int i=0;i<k;i++){
		cin>>xf>>yf>>xs>>ys;
		for(int j=yf;j<ys;j++){
			for(int k=xf;k<xs;k++){
				arr[j][k]=2;//visit을 true로 해서 아예 열외
			}
		}
	}
	
	fill(visited,visited+sizeof(visited),false);//이거의 문제가 아님.
	int result = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
			if(!visited[i][j]&&arr[i][j]==0){
				dfs(i,j);
				result++;
			}
		}
		cout<<endl;
	}
	cout<<result;
}