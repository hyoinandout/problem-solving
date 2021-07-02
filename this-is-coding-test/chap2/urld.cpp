#include <cstdio>
#include <map>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    map<char,pair<int,int>> m;
    m['U']={-1,0};
    m['D']={1,0};
    m['L']={0,-1};
    m['R']={0,1};
    char c;
    pair<int,int> yx = {0,0};
    while(c!='\n'){
        scanf("%c",&c);
        if(yx.first==0||yx.second==0){
            if(c=='U'||c=='L') continue;
        }
        yx.first+=m[c].first;
        yx.second+=m[c].second;
    }
    printf("%d %d",++yx.first,++yx.second);
    return 0;
}