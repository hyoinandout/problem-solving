//실제로 정렬할 때 정답인 기준으로 정렬했지만 그걸 구현할 생각을 못했다. 정렬에 대하여 연습이 필요하다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers){
    vector<string> numbersToString;
    for(auto number:numbers)
    {
        numbersToString.push_back(to_string(number));
    }
    sort(numbersToString.begin(),numbersToString.end(),compare);
    if(numbersToString[0] == "0")
    {
        return "0";
    }
    string answer = "";
    for(auto number:numbersToString)
    {
        answer += number;
    }
    cout<<answer[0]<<endl;
    return answer;
}