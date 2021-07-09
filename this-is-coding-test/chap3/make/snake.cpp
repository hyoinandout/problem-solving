#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n+1][n+1];
    for(int i=0;i<k;i++){
        int y,x;
        scanf("%d %d",&y,&x);
        arr[y][x]=1;
    }
    int l;
    scanf("%d",&l);
    queue<int> timea;
    queue<char> turna; 
    for(int i=0;i<l;i++){
        int t;
        char d;
        scanf("%d %c",&t,&d);
        timea.push(t);
        turna.push(d);
    }
    
    queue<pair<int,int>> q;
    queue<pair<int,int>> check;
    int startY=1;
    int startX=1;
    int time=0;
    int status = 0;
    while(1){
        
        if(startY>n||startX>n||startX<1||startY<1){
            printf("return in out of board\n");
            printf("%d",time);
            return 0;
        }
        time++;
        if(status==0){
            startX++;
        }else if(status==1){
            startY++;
        }else if(status==2){
            startX--;
        }else{
            startY--;
        }
        q.push({startY,startX});
        if(q.size()>3){

        
        for(int i=0;i<q.size();i++){
            pair<int,int> past = q.front();
            if((past.first==startY)&&(past.second==startX)){
                printf("return in cycle\n");
                printf("%d",time);
                return 0;
            }
            check.push(q.front());
            q.pop();
        }
        
        q=check;
        }

        if(time == timea.front()){
            if(status==0){
                if(turna.front()=='L') status = 3;
                else status = 1;
            }
            else if(status==1){
                if(turna.front()=='L') status = 0;
                else status = 2;
            }
            else if(status==2){
                if(turna.front()=='L') status = 1;
                else status = 3;
            }
            else{
                if(turna.front()=='L') status = 2;
                else status = 0;
            }
            timea.pop();
            turna.pop();
        }
        if(arr[startY][startX]==1){
            continue;
        }
        q.pop();
    }
}