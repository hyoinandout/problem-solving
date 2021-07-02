#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator iter;

vector<int> input, P;
int n, k, ct;

int main()
{
	// input
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int in;
        cin >> in;
        input.push_back(in);
    } 

	
	
    for (iter it = input.begin(); it != input.end(); ++it) {
		//멀티탭에 전자기구가 꽂혀있으면 continue
        if (find(P.begin(), P.end(), *it) != P.end()) 
            continue;
        
		//멀티탭이 다 안찼으면 꽂아주고 continue
        if (P.size() < n) {
            P.push_back(*it);
            continue;
        }

		
		//멀티탭 꽉찼고 전자기기 새로운거 써야할때
		
		// 2 3 2 3 1 2 7 에서 1 꽂을때 설명 
		iter last = it, idx = P.begin();
		//탭에서
        for (iter t = P.begin(); t != P.end(); ++t) {
		//1 이후에 2나 3중에서 무엇이 더 나중에 쓰이는가 결정과정
            iter temp = find(it + 1, input.end(), *t);
			
			//만약 2랑 3 둘다 끝날때까지 안나온다? 그럼 먼저 탐색한 순서대로 봅힘
            if (temp > last) {
                idx = t;
                last = temp;
            }
        }
		//탭에 새 기기 꽂아주고
        *idx = *it;
		//횟수 늘려준다
        ct++;
    }
    cout << ct;
}