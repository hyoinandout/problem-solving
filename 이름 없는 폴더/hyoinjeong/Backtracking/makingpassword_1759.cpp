#include <iostream>
#include <algorithm>

using namespace std;

int l,c;
char a[15],p[16];
bool isvowel[26];

void dfs(int pos, int prev, int hvowel, int hcon){
    if(pos==l){
        if(hvowel>=1&&hcon>=2){
            puts(p);
        }
        return;
    }

    for(int i=prev+1;i<c;i++){
        p[pos]=a[i];
        dfs(pos+1,i,hvowel+isvowel[a[i]-'a'],hcon+!isvowel[a[i]-'a']);
    }    
}

int main(){
    cin>>l>>c;
    for(int i=0;i<c;i++){
        scanf(" %c",&a[i]);
    }
    sort(a,a+c);
    isvowel[0]=isvowel[4]=isvowel[8]=isvowel[14]=isvowel[20]=1;
    dfs(0,-1,0,0);
}