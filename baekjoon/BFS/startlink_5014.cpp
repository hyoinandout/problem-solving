//u나d가 0일때뿐만 아니라 s 1 g 1000000 인데 u 1000000 인 경우도 안된다.
#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];

void bfs(int f,int s,int g, int u, int d){
    queue<int> Q;
    Q.push(s);
    visited[s]=1;
    int level = 0;
    bool pandog =true;        
    while(!Q.empty()&&pandog){
        int qsize = Q.size();
        if(visited[g]){
            cout<<level<<endl;
            pandog=false;
            return;
        }
        for(int i=0;i<qsize;i++){
            int curr = Q.front();
            Q.pop();
            int tu=curr+u;
            if(!visited[tu]&&tu<=f){
                visited[tu]=1;
                Q.push(tu);
            }
            
            int td=curr-d;
            if(!visited[td]&&td>=1){
                visited[td]=1;
                Q.push(td);
            }
        }
        level++;
    }
    if(!visited[g]){
        cout<<"use the stairs"<<endl;
        return;
    }
}

int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    bfs(f,s,g,u,d);
    return 0;
}