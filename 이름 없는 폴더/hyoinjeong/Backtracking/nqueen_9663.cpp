#include <iostream>
#include <cmath>

using namespace std;

int n, cnt;
int col[15];

bool check(int level){
    for(int i=0;i<level;i++){
        if(col[i]==col[level]||abs(col[level]-col[i])==level-i)
            return false;
    }
    return true;
}



void bt(int x){
    if(x==n){
        cnt++;
    }
    else{
        for(int i=0;i<n;i++){
            col[x]=i;
            if(check(x)){
                bt(x+1);
            }
        }
    }
}

int main(){
    cin>>n;
    bt(0);
    cout<<cnt<<endl;
    return 0;
}