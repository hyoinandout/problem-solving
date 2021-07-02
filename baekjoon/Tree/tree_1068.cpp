#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> par (51,-10);

bool check[51];
int result=0;

void cnt(int k){
    par[k]=-10;
    bool isLeaf =true;
    for(int i=0;i<n;i++){
        if(par[i]==k){
            isLeaf=false;
            cnt(i);
        }
    }
    if(isLeaf) result++;
}

void er(int k){
    par[k]=-10;
    for(int i=0;i<n;i++){
        if(par[i]==k){
            er(i);
        }
    }
}

int main(){
    cin>>n;
    int input,root;
    for(int i=0;i<n;i++){
        cin>>input;
        if(input==-1) root=i;
        else par[i]=input;
    }

    int del;
    cin>>del;
    if(del==root) cout<<"0"<<endl;
    else{
        er(del);
        cnt(root);
        cout<<result<<endl;
    }
    return 0;
}