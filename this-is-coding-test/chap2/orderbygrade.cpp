#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string name;
    int grade;
    vector<pair<int,string>> v;
    for(int i=0;i<n;i++){
        cin>>name>>grade;
        v.push_back({grade,name});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].second<<' ';
    }
    return 0;
}