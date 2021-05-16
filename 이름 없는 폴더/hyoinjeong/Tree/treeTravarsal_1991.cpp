#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Tree{
public:
    int N;
    vector<char> parent;
    vector<char> lc, rc;

    Tree(): N(0){}
    Tree(int n): N(n){
        parent.resize(N,'.');
        lc.resize(N,'.');
        rc.resize(N,'.');
    }

    void setChildren(char p, char l, char r){
        if(l!='.') parent[l-'A']=p;
        if(r!='.') parent[r-'A']=p;
        lc[p-'A']=l;
        rc[p-'A']=r;
    }

    void preOrder(char root){
        cout<<root;
        if(lc[root-'A']!='.') preOrder(lc[root-'A']);
        if(rc[root-'A']!='.') preOrder(rc[root-'A']);
    }

    void inOrder(char root){
        if(lc[root-'A']!='.') inOrder(lc[root-'A']);
        cout<<root;
        if(rc[root-'A']!='.') inOrder(rc[root-'A']);
    }

    void postOrder(char root){
        if(lc[root-'A']!='.') postOrder(lc[root-'A']);
        if(rc[root-'A']!='.') postOrder(rc[root-'A']);
        cout<<root;
    }
};

int main(){
    int n;
    cin>>n;
    Tree T(n);
    char p,l,r;
    for(int i=0;i<n;i++){
        cin>>p>>l>>r;
        T.setChildren(p,l,r);
    }
    T.preOrder('A');
    cout<<endl;
    T.inOrder('A');
    cout<<endl;
    T.postOrder('A');
    cout<<endl;
    return 0;
}