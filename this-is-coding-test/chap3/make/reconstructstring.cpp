#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int result=0;
    string k;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'>9){
            k.push_back(s[i]);
        }else{
            result+=s[i]-'0';
        }
    }
    sort(k.begin(),k.end());
    cout<<k<<result<<endl;
}