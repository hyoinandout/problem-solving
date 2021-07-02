//c++ priority queue 신경쓰기
#include <bits/stdc++.h>

using namespace std;
int n,m,c;
vector<pair<int,int>> graph[30001];
int dist[30001];
//bool visited[30001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;
    //for(int i=0;i<pq.size();i++){
    while(!pq.empty()){
        int k = -pq.top().first;
        int present = pq.top().second;
        pq.pop();
        if(dist[present]<k) continue;
        
        //if(visited[present]) continue;
        //visited[present]=true;
        for(int j=0;j<graph[present].size();j++){
            //if(dist[graph[present][j].second]>k+graph[present][j].first){
            int cost = k + graph[present][j].second;
            if(cost<dist[graph[present][j].first]){
                dist[graph[present][j].first] = cost;
                pq.push({-cost,graph[present][j].first});
            }
        }
     }
}


int main(){
    fill_n(dist, 30001, 987654321);
    scanf("%d %d %d",&n,&m,&c);
    for(int i=0;i<m;i++){
        int start,end,distance;
        scanf("%d %d %d",&start,&end,&distance);
        graph[start].push_back({end,distance});
        graph[end].push_back({start,distance});
    }
    dijkstra(c);
    int cnt= 0;
    int result = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]>=9876454321) continue;
        ++cnt;
        result = max(result,dist[i]);
    }
    printf("%d %d",cnt-1,result);
    return 0;
}