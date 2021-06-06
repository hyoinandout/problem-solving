#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int in[501];
int price[501];
int n;
//문제1
// vector<vector<int>> arr(501);
vector<int> arr[501];

void topology_sort(){
    queue<int> q;
    int result[n+1];
    int cpin[n+1];
    for(int i=1;i<=n;i++){
        cpin[i]=in[i];
        //문제2 : result 초기화 안해줬음
        result[i]=price[i];
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
        }
    }
    // bool pandog=true;
    while(!q.empty()){
        // int size = q.size();
        // int realprice=0;
        // for(int j=0;j<size;j++){
            int now = q.front();
            q.pop();
            // realprice=max(realprice,price[now]);
            // if(now==x){
            //     result+=price[now];
            //     return result;
            // }
            for(int i=0;i<arr[now].size();i++){
                result[arr[now][i]] = max(result[arr[now][i]],result[now]+price[arr[now][i]]);
                cpin[arr[now][i]]-=1;
                if(!cpin[arr[now][i]]){
                    q.push(arr[now][i]);
                }
            }
        
        // result+=realprice;
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",result[i]);
    }
    return;
}

int main(){
    
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        price[i]=x;
        int k;
        while(1){
            scanf("%d",&k);
            if(k==-1) break;
            //문제 3 : 무엇이 선행과목인가?
            arr[k].push_back(i);
            in[x]+=1;           
        }
    }
    topology_sort();
    return 0;
}