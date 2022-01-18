#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int n;
//std::set<int> team;
std::vector<int> team;
// std::set<std::set<int>> visitedTeam;
std::set<std::vector<int>> visitedTeam;
bool visited[21];
int finalResult = 40001;
void start_link(std::vector<std::vector<int>>& array, int index, int cnt)
{
    if(cnt == (n / 2)){
        if(visitedTeam.find(team) != visitedTeam.end()){
            return;
        }
        int team1 = 0;
        int team2 = 0;
        std::vector<int> oppositeTeam;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(team.find(i) != team.end() && team.find(j) != team.end()){
        //             team1 += array[i][j];
        //             team1 += array[j][i];
        //         }else if(team.find(i) == team.end() && team.find(j) == team.end()) {
        //             oppositeTeam.insert(i);
        //             oppositeTeam.insert(j);
        //             team2 += array[i][j];
        //             team2 += array[j][i];
        //         }
        //     }
        // }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                oppositeTeam.push_back(i);
            }
            for(int j = i+1; j < n; j++){
                if(visited[i] && visited[j]){
                    team1 += array[i][j];
                    team1 += array[j][i];
                } else if(!visited[i] && !visited[j]){
                    team2 += array[i][j];
                    team2 += array[j][i];
                }
            }
        }
        visitedTeam.insert(oppositeTeam);
        finalResult = std::min(finalResult,std::abs(team1-team2));
    }
    for(int i = index; i < n; i++){
        //team.insert(i);
        team.push_back(i);
        visited[i] = true;
        start_link(array,i+1,cnt+1);
        //team.erase(i);
        team.pop_back();
        visited[i] = false;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin>>n;
    std::vector<std::vector<int>> capacityArray(n,std::vector<int> (n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            std::cin>>x;
            capacityArray[i][j] = x;
        }
    }
    start_link(capacityArray,0,0);
    std::cout<<finalResult;
}