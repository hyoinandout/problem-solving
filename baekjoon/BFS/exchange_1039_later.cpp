#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
 
int main(){
    string N, result = "0";
    int K;
    scanf("%d %d", &N, &K);
    queue<string> q;
    q.push(N);
 
    // BFS 시작
    for(int i=0; i<K; i++){
        int qSize = q.size();
        set<string> found;
        // string이기 때문에 배열 사용 불가능. 대신 set 사용
        for(int j=0; j<qSize; j++){
            string str = q.front();
            q.pop();
            if(found.count(str)) continue;
            found.insert(str);
            // 모든 가능한 쌍 시도
            for(int k=0; k<str.size()-1; k++)
                for(int l=k+1; l<str.size(); l++)
                    // k가 제일 큰 자리가 아니거나, l 자리가 0이 아니면 교환
                    if(k>0 || str[l]!='0'){
                        // string이라 swap은 쉽다.
                        swap(str[k], str[l]);
                        q.push(str);
                        swap(str[k], str[l]);
                    }
        }
    }
 
    // 정답을 찾아냄
    while(!q.empty()){
        result = max(result, q.front());
        q.pop();
    }
    if(result[0] == '0') puts("-1");
    else printf("%s\n", result);
}
//[출처] [1039번] 교환|작성자 라이

