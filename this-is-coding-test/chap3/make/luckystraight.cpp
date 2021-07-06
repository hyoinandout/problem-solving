#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int result = 0;
    for(int i=0;i<s.length()/2;i++){
        result+=s[i]-'0';
    }
    for(int i=s.length()/2;i<s.length();i++){
        result-=s[i]-'0';
    }
    if(result==0){
        cout<<"LUCKY"<<endl;
    }else{
        cout<<"READY"<<endl;
    }
}