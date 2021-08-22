//시간 제한도 힌트
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    int x,y,a,b;
    vector<vector<int>> wall(n+1,vector<int>(n+1,2));
    vector<vector<int>> answer;
    
    for(int i=0;i<build_frame.size();i++){
        x=build_frame[i][0];
        y=build_frame[i][1];
        a=build_frame[i][2];
        b=build_frame[i][3];
        vector<int> ans;
        if(a==0){
            if(b==0){
                if(y==0||wall[y][x]!=2){
                    wall[y][x]=0;
                    wall[y+1][x]=0;
                }
                else continue;
            }else if(b==1){
                if(wall[y+1][x]==1){
                    if(wall[y][x+1]==1&&wall[y][x-1]==1){
                        wall[y][x]=2;
                    }else continue;
                }else if(wall[y+1][x]==0){
                    if(wall[y][x+1]==1&&wall[y][x-1]==1){
                        wall[y][x]=2;
                    }else continue;
                }else continue;
            }
            ans.push_back(x);
            ans.push_back(y);
            ans.push_back(a);
            answer.push_back(ans);
        }else if(a==1){
            if(b==0){
                if(wall[y-1][x]==0||wall[y-1][x+1]==0||(wall[y][x]==1)&&(wall[y][x+1]==1)){
                    wall[y][x]=1;
                    wall[y][x+1]=1;
                }
                else continue;
            }else if(b==1){
                if(wall[y-1][x+1]==0||wall[y-1][x-1]==0||wall[y-1][x-2]==0||wall[y-1][x+2]==0){
                    wall[y][x]=2;
                }else continue;
            }
            ans.push_back(x);
            ans.push_back(y);
            ans.push_back(a);
            auto it = remove(answer.begin(), answer.end(), ans);
	        answer.resize( it - answer.begin());
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}