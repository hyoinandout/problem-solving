//알고리즘 생각한 것도 틀림
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int parent[100001];
int find_parent(int a){
    if(parent[a]!=a){
        parent[a]=find_parent(parent[a]);
    }
    return parent[a];
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    // 아래의 방법 실패(vector 관련 메모리 문제)
    // vector<vector<pair<int,int>>> dist;
    vector<pair<int,pair<int,int>>> dist;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        dist.push_back({c,{a,b}});
    }
    int result=0;
    // int cnt=0;
    int last;
    sort(dist.begin(),dist.end());
    //중간에 distance가 없다면?
    for(int i=0;i<dist.size();i++){
        
            int cost =dist[i].first;
            int x = dist[i].second.first;
            int y = dist[i].second.second;
            if(find_parent(x)==find_parent(y)) continue;
            // if(parent[x]==parent[y]) continue;
            else{
                // cnt++;
                result+=cost;
                last=cost;
                // 아래의 방법은 확실하지 않다
                // if(cnt==n-2){
                //     printf("%d",result);
                //     return 0;
                // }
                x=find_parent(x);
                y=find_parent(y);
                x<y?parent[y]=parent[x]:parent[x]=parent[y];
                // 트리의 성질을 이용하자! (노드개수 -1 = 간선개수)
                // int cnt=0;
                // for(int i=1;i<=n;i++){
                //     if(parent[i]!=parent[i-1]) cnt++;
                // }
                // if(cnt==2){
                //     printf("%d", result);
                //     return 0;
                // } 
                // for(int i=1;i<=n;i++){
                //     parent[i]=find_parent(i);
                //     // parent[y]=find_parent(y);
                // }
            }
        }
        printf("%d",result-last);
}