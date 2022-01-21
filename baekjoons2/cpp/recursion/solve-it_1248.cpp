#include <stdio.h>
#include <vector>
#include <algorithm>

int n;
char array[11][11];
std::vector<int> answer;
std::vector<std::vector<int>> partialSum(11,std::vector<int> (11,0));

void generate_combinations(int cnt){
    if(cnt == n){
        for(auto element : answer){
            printf("%d ",element);
        }
        printf("\n");
        //return;
        exit(0);
    }
    bool visited[21];
    std::fill(visited,visited+21,true) ;
    for(int i = 0; i <=cnt; i++){
        if(array[i][cnt] == '-'){
            for(int j = -10; j < 11; j++){
                if (partialSum[i][cnt-1] + j >= 0){
                    visited[j+10] = false;
                }
            }
        } else if(array[i][cnt] == '+'){
            for(int j = -10; j < 11; j++){
                if (partialSum[i][cnt-1] + j <= 0){
                    visited[j+10] = false;
                }
            }
        } else{
            for(int j = -10; j < 11; j++){
                if (partialSum[i][cnt-1] + j != 0){
                    visited[j+10] = false;
                }
            }
        }
    }
    for(int i = 0; i < 21; i++){
        if(visited[i]){
            answer.push_back(i-10);
            for(int j = 0; j <= cnt; j++){
                partialSum[j][cnt] = partialSum[j][cnt-1] + i-10;
            }
            generate_combinations(cnt+1);
            answer.pop_back();
            for(int j = 0; j <= cnt; j++){
                partialSum[j][cnt] = 0;
            }
        }
    }
}

int main(){
    scanf("%d\n",&n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            scanf("%1c",&array[i][j]);
        }
    }
    
    if(array[0][0] == '-'){
        for(int i = -10; i < 0; i++){
            answer.push_back(i);
            partialSum[0][0] = i;
            generate_combinations(1);
            answer.pop_back();
            partialSum[0][0] = 0;
        }
    } else if(array[0][0] == '+'){
        for(int i = 1; i < 11; i++){
            answer.push_back(i);
            partialSum[0][0] = i;
            generate_combinations(1);
            answer.pop_back();
            partialSum[0][0] = 0;
        }
    } else{
        answer.push_back(0);
        generate_combinations(1);
        answer.pop_back();
    }
}