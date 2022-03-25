#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>


using namespace std;

map<string,bool> visited;
set<string> related;
void dfs(string k, unordered_map<string,vector<string>>& m)
{
    visited[k] = true;
    related.insert(k);
    for(auto x:m[k])
    {
        if(!visited[x])
        {
            dfs(x,m);
        }
    }
}

//dfs로 추출 후 위상정렬
vector<string> solution(vector<string> s1, vector<string> s2, string k) {
    vector<string> answer;

    //추출
    int n = s1.size();
    unordered_map<string,vector<string>> refine;
    map<string,vector<string>> m;
    map<string,int> indegree;
    for(int i=0;i<n;i++)
    {
        refine[s2[i]].push_back(s1[i]);
        m[s1[i]].push_back(s2[i]);
        indegree[s2[i]]+=1;
    }
    dfs(k,refine);
    priority_queue<string,vector<string>,greater<string>> q;
    for(auto x:related)
    {
        if(indegree[x] == 0)
        {
            q.push(x);
        }
    }

    while(!q.empty())
    {
        string s = q.top();
        q.pop();

        answer.push_back(s);
        for(auto x:m[s])
        {
            indegree[x] -= 1;
            if(indegree[x] == 0 && related.count(x) != 0)
            {
                q.push(x);
            }
        }
    }
    return answer;
}

int main()
{
    for(auto x: solution({"A", "E", "B", "D", "B", "H", "F", "H", "C"},{"G", "C", "G", "F", "J", "E", "B", "F", "B"},"B"))
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x: solution({"A", "E", "B", "D", "B", "H", "F", "H", "C"},{"G", "C", "G", "F", "J", "E", "B", "F", "B"},"G"))
    {
        cout<<x<<" ";
    }
    cout<<endl;
}