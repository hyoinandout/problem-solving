#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Hash(vector<string> p, vector<string> c);

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int index = Hash(participant, completion);
    
    string answer = participant[index];
    return answer;
}
int Hash(vector<string> p, vector<string> c)
{
    
    
    for(int i=0;i<p.size();i++)
    {
        if(p[i] != c[i])
        {
            return i;
        }
    }
    return p.size()-1;
}