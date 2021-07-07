#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int length=1001;
    for(int i=1;i<=s.length()/2;i++){
        string past = s.substr(0,i);
        cout<<"out side for loop past string "<<past<<endl;
        int cnt=1;
        string result;
        for(int j=i;j<s.length();j+=i){
            if(past!=s.substr(j,i)){
                if(cnt>=2){
                    result.append(to_string(cnt));
                }
                result.append(past);
                cout<<"result of appending unmatch string "<<result<<endl;
                cout<<"j "<<j<<" j+i "<<j+i<<endl;
                past = s.substr(j,i);
                cout<<"After unmatch past string "<<past<<endl;
                cnt=1;
                continue;
            }
            cnt++;
        }
        if(cnt>=2){
            result.append(to_string(cnt));
        }
        // result.append(s.substr(s.length()-(i+s.length()%i),i+s.length()%i));
        result.append(past);
        cout<<"result string "<<result<<endl;
        length=min(length,(int)result.length());
    }
    length=min(length,(int)s.length());
    cout<<length<<endl;
}