#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i=0;i<number.length();i++)
    {
        while(k>0 && !answer.empty())
        {
            if(answer.back() < number[i])
            {
                answer.pop_back();
                k -= 1;
            }
            else
            {
                break;
            }
        }
        answer += number[i];
    }
    while(k>0 && !answer.empty())
    {
        answer.pop_back();
        k -= 1;
    }
    return answer;
}

int main()
{
    cout<<solution("1924",2)<<endl;
    cout<<solution("1231234",3)<<endl;
    cout<<solution("4177252841",4)<<endl;
    cout<<solution("654321",1)<<endl;
    cout<<solution("654321",5)<<endl;
}