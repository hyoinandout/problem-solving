#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <vector<string>> clothes;
    int count = 1;
    int answer = 1;
    vector<int> c(30);
    for(int i = 0; i < clothes.size(); i++)
    {
        for(int j = 0; j <  clothes[i].size(); j++)
        {
            iter_swap(clothes[i].begin(),clothes[i].end()-1);
        }
    }
    sort(clothes.begin(),clothes.end());
    for(int i=0;i<clothes.size();i++)
    {
        if(clothes[i].begin()==clothes[i+1].begin())
        {
            count++;
        }
        else
        {
            c.push_back(count+1);
            count = 1;
        }
    }
    c.push_back(count+1);
    for(int j = 0;j< c.size();j++)
    {
        answer*=c[j];
    }
    return (answer-1);
}