//상하좌우 다 봐야하는 이유: 대서양의 무인도
#include <bits/stdc++.h>

using namespace std;

char pic[100][100];
int N;
int arrx[4] = {-1,1,0,0};
int arry[4] = {0,0,-1,1};
bool visited[100][100];

void dfs(int row, int column)
{
	visited[row][column]=true;
	for(int i=0;i<4;i++){
		int xi=row+arry[i];
		int yi=column+arrx[i];
		if(xi<0||yi<0||xi>=N||yi>=N) continue;
		if(pic[row][column]==pic[xi][yi]&&!visited[xi][yi])
			dfs(xi,yi);
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>pic[i][j];
		}
	}
	int result=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				dfs(i,j);
				result++;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
			if(pic[i][j]=='G')
				pic[i][j]='R';
			}
	}
	int result2 = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				dfs(i,j);
				result2++;
			}
		}
	}
	cout<<result<<" "<<result2<<endl;
}