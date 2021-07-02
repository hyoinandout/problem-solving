#include <iostream>
#include <string>

using namespace std;

int m;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>m;
    int k = 1<<21;
    string s;
    int d;
    for(int i=0;i<m;i++){
        cin>>s;
        if(s=="add"){
            cin>>d;
            k|=1<<(d-1);
        }
        else if(s=="remove"){
            cin>>d;
            k&=~(1<<(d-1));
        }
        else if(s=="check"){
            cin>>d;
            bool z =k&(1<<(d-1));
            cout<<z<<endl;
        }
        else if(s=="toggle"){
            cin>>d;
            if(k&(1<<(d-1))){
                k&=~(1<<(d-1));
            }
            else{
                k|=(1<<(d-1));
            }
        }
        else if(s=="all"){
            k=(1<<21)-1;
        }
        else{
            k=1<<21;
        }
    }    
    return 0;
}