#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Hash(vector<string> p, vector<string> c);

string solution(vector<string> participant, vector<string> completion) {
	int i;
	sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(i=0;i<participant.size();i++)
    {
        if(participant[i] != completion[i])
        {
            return participant[i];
        }
    }
    return participant[i];
}