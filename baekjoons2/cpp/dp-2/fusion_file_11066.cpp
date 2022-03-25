// 순서가 있어서 heap으로 풀 수 없다.
// dp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int k;
        cin>>k;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j=0;j<k;j++)
        {
            int page;
            cin>>page;
            pq.push(page);
        }
        int result = 0;
        while(pq.size()>= 2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int c = (a+b);
            result += c;
            pq.push(c);
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        // int x = pq.top();
        // pq.pop();
        // result += x;
        cout<<result<<endl;
    }
}