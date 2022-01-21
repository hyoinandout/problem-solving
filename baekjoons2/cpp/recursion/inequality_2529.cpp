#include <iostream>
#include <vector>
#include <string>

int k;
std::vector<char> inequality;
std::string minResult = "9876543210";
std::string maxResult = "0";
bool visited[10];
std::string ans = "";

void f(int index, int cnt){
    if(cnt == k+1){
        if(ans > maxResult){
            maxResult = ans;
        }
        if(ans < minResult){
            minResult = ans;
        }
        return;
    }
    if(inequality[cnt-1] == '>'){
        for(int i = index-1; i >= 0; i--){
            if(visited[i]){
                continue;
            }
            char x = '0' + i;
            visited[i] = true;
            ans.push_back(x);
            f(i,cnt+1);
            visited[i] = false;
            ans.pop_back();
        }
    } else{
        for(int i = index+1; i < 10; i++){
            if(visited[i]){
                continue;
            }
            char x = '0' + i;
            visited[i] = true;
            ans.push_back(x);
            f(i,cnt+1);
            visited[i] = false;
            ans.pop_back();            
        }
    }
}

int main(){
    std::cin>>k;
    for(int i=0; i<k; i++){
        char x;
        std::cin>>x;
        inequality.push_back(x);
    }
    for(int i = 0; i < 10; i++){
        char x = '0' + i;
        visited[i] = true;
        ans.push_back(x);
        f(i,1);
        visited[i] = false;
        ans.pop_back();
    }
    std::cout<<maxResult<<"\n";
    std::cout<<minResult<<"\n";
}