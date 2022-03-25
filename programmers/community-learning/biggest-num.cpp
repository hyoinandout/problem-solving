//������ ������ �� ������ �������� ���������� �װ� ������ ������ ���ߴ�. ���Ŀ� ���Ͽ� ������ �ʿ��ϴ�.
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