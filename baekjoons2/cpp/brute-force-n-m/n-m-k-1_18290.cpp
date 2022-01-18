#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int n,m,k;
std::vector<int> results;
bool visited[11][11];
// int dx[2] = {1,0};
// int dy[2] = {0,1};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isVisited(int i, int j){
    for(int k = 0; k < 4; k++){
        int ni = i + dy[k];
        int nj = j + dx[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(visited[ni][nj]){
                return true;
            }
        }
    }
    return false;
}


void n_m_k(std::vector<std::vector<int>>& board,int index, int now, int sum){
    if(now == k){
        results.push_back(sum);
        return;
    }
    // for(int k = 0; k < 2; k++){
    //     int ni = index / m + dy[k];
    //     int nj = index % m + dx[k];
    //     if(ni >= 0 && ni < n && nj >= 0 && nj < m){
    //         visited[ni][nj] = true;
    //     }
    // }
    int result = 0;
    for(int i = (index / m); i < n; i++){
        if(i == (index / m)){
            for(int j = index % m; j < m; j++){
                if(visited[i][j] || isVisited(i,j)) {
                    continue;
                }

                visited[i][j] = true;
                n_m_k(board,i*m+j,now+1,sum+board[i][j]);
                visited[i][j] = false;
            }
        } else{
            for(int j = 0; j < m; j++){
                if(visited[i][j] || isVisited(i,j)) {
                    continue;
                }
                visited[i][j] = true;
                n_m_k(board,i*m+j,now+1,sum+board[i][j]);
                visited[i][j] = false;
            }
        }
    }
    // for(int k = 0; k < 2; k++){
    //     int ni = index / m + dy[k];
    //     int nj = index % m + dx[k];
    //     if(ni >= 0 && ni < n && nj >= 0 && nj < m){
    //         visited[ni][nj] = false;
    //     }
    // }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> board(n,std::vector<int> (m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            std::cin>>x;
            board[i][j] = x;
        } 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            n_m_k(board,i*m+j,1,board[i][j]);
            visited[i][j] = false;
        }
    }
    int answer = *std::max_element(results.begin(),results.end());
    std::cout<<answer;
    return 0;
}