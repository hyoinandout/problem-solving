#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool S[21];
int m;

int main(){
    cin>>m;
    string command;
    memset(S,0,sizeof(S));
    for(int i=0;i<m;i++){
        int k;
        cin>>command;
        if(command=="add"){
            cin>>k;
            S[k]=true;
        }
        else if(command=="remove"){
            cin>>k;
            S[k]=false;
        }
        else if(command=="check"){
            cin>>k;
            if(S[k]){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else if(command=="toggle"){
            cin>>k;
            ~S[k];
        }
        else if(command=="all"){
            for(int i=1;i<21;i++){
                S[k]=true;
            }
        }
        else{
            for(int i=1;i<21;i++){
                S[k]=false;
            }
        }
    }
    return 0;
}