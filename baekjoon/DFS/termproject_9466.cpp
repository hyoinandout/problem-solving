#include <iostream>
#include <algorithm>

using namespace std;

int a[100000],cnt,n;
bool visit[100000],finish[100000];

void dfs(int curr){
	visit[curr]=true;
	int next = a[curr];
	if(visit[next]){
		if(!finish[next]){
			for(int temp=next;temp!=curr;temp=a[temp]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finish[curr]=true;
}


int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",a+j);
			a[j]--;
		}
		fill(visit,visit+n,false);
		fill(finish,finish+n,false);
		cnt=0;
		for(int j=0;j<n;j++){
			if(!visit[j]) dfs(j);
		}
		cout<<n-cnt<<endl;
	}
}