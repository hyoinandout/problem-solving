#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> l;
    stack<int> r;
    stack<int> s;
    for(int i=0;i<k;i++){
        l.push(i);
    }
    for(int i=n-1;i>=k;i--){
        r.push(i);
    }
    for(int i=0;i<cmd.size();i++){
        if(r.empty()){
            int a =l.top();    
            l.pop();
            r.push(a);
        }
        if(cmd[i][0]=='D'){
            for(int j=0;j<(int)(cmd[i][2]-'0');j++){
                int a=r.top();
                l.push(a);
                r.pop();
            }
        }
        else if(cmd[i][0]=='U'){
            for(int j=0;j<(int)(cmd[i][2]-'0');j++){
                int a=l.top();
                r.push(a);
                l.pop();
            }
        }
        else if(cmd[i][0]=='C'){
            int a =r.top();    
            r.pop();
            s.push(a);
        }
        else if(cmd[i][0]=='Z'){
            int a = s.top();
            s.pop();
            if(a>r.top()){
                stack<int> temp;
                int b = r.top();
                temp.push(b);
                r.pop();
                
                while(a>r.top()){
                    int c = r.top();
                    temp.push(c);
                    r.pop();
                }
                r.push(a);
                while(!temp.empty()){
                    int d = temp.top();
                    r.push(d);
                    temp.pop();
                }
            }
            else{
                stack<int> temp;
                while(a<l.top()){
                    int c = l.top();
                    temp.push(c);
                    l.pop();
                }
                l.push(a);
                while(!temp.empty()){
                    int d = temp.top();
                    l.push(d);
                    temp.pop();
                }
            }
        }
        
    }
    
    string answer = "";
    for(int i=0;i<n;i++){
        answer+='O';
    }
    while(!s.empty()){
       int k = s.top();
       s.pop();
       answer[k]='X';
    }
    return answer;
};

int main(){
    int n=8, k=2;
    vector<string> s;
    s.push_back("D 2");
    s.push_back("C");
    s.push_back("U 3");
    s.push_back("C");
    s.push_back("D 4");
    s.push_back("C");
    s.push_back("U 2");
    s.push_back("Z");
    s.push_back("Z");
    
    cout<<solution(n,k,s)<<endl;
    return 0;
}