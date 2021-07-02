#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N,T,G;
bool visited[100000];

void bfs(){
    queue<int> Q;
    visited[N]=true;
    Q.push(N);
    int level = 0;
    while(!Q.empty()){
        if(visited[G]){
            if(level<=T)
                cout<<level<<endl;
            else
                cout<<"ANG"<<endl;
            return;
        }
        int qsize = Q.size();
        for(int i=0;i<qsize;i++){
            int curr = Q.front();
            Q.pop();
            int a = curr + 1;
            if(!visited[a]&&a<=99999){
                visited[a]=1;
                Q.push(a);
            }
            if(curr==0) continue;
            string temp = to_string(curr * 2);
            temp[0]-=1;
            int b = stoi(temp);
            if(!visited[b]&&curr<50000){
                visited[b]=1;
                Q.push(b);
            }
        }
        level++;
    }
    cout<<"ANG"<<endl;
    return;
}

int main(){
    cin>>N>>T>>G;
    bfs();
    return 0;
}