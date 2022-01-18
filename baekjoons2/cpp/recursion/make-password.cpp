#include <iostream>
#include <vector>
#include <algorithm>
int l,c;
std::vector<char> ch;
std::vector<bool> vowel(26);
std::vector<char> answer;
void make_password(int prev, int cnt, int vowelCnt, int notVowelCnt)
{
    if(cnt == l){
        if((vowelCnt >= 1) && (notVowelCnt >= 2)){
            for(auto character : answer){
                std::cout<<character;
            }
            std::cout<<"\n";
        }
        return;
    }

    for(int i = prev+1; i < c; i++){
        answer.push_back(ch[i]);
        int x = (int)(ch[i]-'a');
        if(vowel[x]){
            make_password(i, cnt+1, vowelCnt+1, notVowelCnt);
        } else{
            make_password(i, cnt+1, vowelCnt, notVowelCnt+1);
        }
        answer.pop_back();
    }

}

int main()
{
    std::cin>>l>>c;
    for(int i = 0; i < c; i++){
        char x;
        std::cin>>x;
        ch.push_back(x);
    }
    vowel[0] = vowel[4] = vowel[8] = vowel[14] = vowel[20] = true;
    std::sort(ch.begin(),ch.end());
    make_password(-1,0,0,0);
}