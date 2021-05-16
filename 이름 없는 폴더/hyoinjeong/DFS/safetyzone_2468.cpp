#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int height[100][100];
bool visit[100][100];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int x, int y, int rain){
	visit[x][y]=true;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=N) continue;
		if((!visit[nx][ny])&&(height[nx][ny]>rain)) dfs(nx,ny,rain);
	}
}

int main(){
	cin>>N;
	int maxrain=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>height[i][j];
			maxrain=max(maxrain,height[i][j]);
		}
	}
	
	int maxzone=0;
	//cout<<maxrain<<endl;
	for(int i=0;i<=maxrain;i++){
		int zone=0;
		memset(visit, false, sizeof(visit));
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if((height[j][k]>i)&&(!visit[j][k])){
					dfs(j,k,i);
					zone++;
				}
			}
		}
		//cout<<i<<" "<<zone<<endl;
		maxzone=max(maxzone,zone);
	}
	cout<<maxzone<<endl;
}