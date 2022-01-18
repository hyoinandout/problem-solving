#include <iostream>
#include <vector>
#include <algorithm>

int ttype(std::vector<std::vector<int>>& board, int y, int x, int n, int m){
    int result = 0;
    int tSum = 0;
    if(((y + 1) < n) && (x + 2) < m){
        tSum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y][x+2];
    }
    result = std::max(result,tSum);
    int fSum = 0;
    if(((y + 2) < n) && (x + 1) < m){
        fSum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x];
    }
    result = std::max(result,fSum);
    int oSum = 0;
    if(((y - 1) >= 0) && (x + 2) < m){
        oSum = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y][x+2];
    }
    result = std::max(result,oSum);
    int eoSum = 0;
    if(((y + 1) < n) && ((y - 1) >= 0) && ((x + 1) < m)){
        eoSum = board[y][x] + board[y-1][x+1] + board[y][x+1] + board[y+1][x+1];
    }
    result = std::max(result,eoSum);
    return result;
}

int ntype(std::vector<std::vector<int>>& board, int y, int x, int n, int m){
    int result = 0;
    int thunderSum = 0;
    if(((y + 2) < n) && (x + 1) < m){
        thunderSum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x+1];
    }
    result = std::max(result,thunderSum);
    int _thunderSum = 0;
    if(((y -1) >= 0) && ((y + 1) < n) && (x + 1) < m){
        _thunderSum = board[y][x] + board[y+1][x] + board[y][x+1] + board[y-1][x+1];
    }
    result = std::max(result,_thunderSum);
    int lyingThunderSum = 0;
    if(((y - 1) >= 0) && (x + 2) < m){
        lyingThunderSum = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y-1][x+2];
    }
    result = std::max(result,lyingThunderSum);
    int _lyingThunderSum = 0;
    if(((y + 1) < n) && (x + 2) < m){
        _lyingThunderSum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+1][x+2];
    }
    result = std::max(result,_lyingThunderSum);
    return result;
}

int ltype(std::vector<std::vector<int>>& board, int y, int x, int n, int m){
    int result = 0;
    int lSum = 0;
    if(((y + 2) < n) && (x + 1) < m){
        lSum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+2][x+1];
    }
    result = std::max(result, lSum);
    int __lSum = 0;
    if(((y - 2) >= 0) && (x + 1) < m){
        __lSum = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y-2][x+1];
    }
    result = std::max(result, __lSum);
    int rSum = 0;
    if(((y + 1) < n) && (x + 2) < m){
        rSum = board[y][x] + board[y+1][x] + board[y][x+1] + board[y][x+2];
    }
    result = std::max(result, rSum);
    int _rSum = 0;
    if(((y + 1) < n) && (x + 2) < m){
        _rSum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+1][x+2];
    }
    result = std::max(result, _rSum);
    int tSum = 0;
    if(((y + 2) < n) && (x + 1) < m){
        tSum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+2][x+1];
    }
    result = std::max(result, tSum);
    int _tSum = 0;
    if(((y + 2) < n) && (x + 1) < m){
        _tSum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y][x+1];
    }
    result = std::max(result, _tSum);
    int _lSum = 0;
    if(((y - 1) >= 0) && (x + 2) < m){
        _lSum = board[y][x] + board[y-1][x+2] + board[y][x+1] + board[y][x+2];
    }
    result = std::max(result, _lSum);
    int ___lSum = 0;
    if(((y + 1) < n) && (x + 2) < m){
        ___lSum = board[y][x] + board[y][x+2] + board[y][x+1] + board[y+1][x+2];
    }
    result = std::max(result, ___lSum);
    return result;
}

int squaretype(std::vector<std::vector<int>>& board, int y, int x, int n, int m){
    if((y + 1 >= n)||(x+1 >= m)){
        return 0;
    }
    int result = board[y][x] + board[y][x+1] + board[y+1][x] + board[y+1][x+1];
    return result;
}

int linetype(std::vector<std::vector<int>>& board, int y, int x, int n, int m){
    int ySum = 0;
    int xSum = 0;
    if((y + 3) < n){
        ySum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+3][x];
    }
    if((x + 3) < m){
        xSum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y][x+3];
    }
    int result = xSum > ySum? xSum: ySum;
    return result;
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> array(n,std::vector<int> (m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            std::cin>>x;
            array[i][j] = x;
        }
    }
    int candid[5] = {0,0,0,0,0}; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            candid[0] = std::max(candid[0],ttype(array,i,j,n,m));
            candid[1] = std::max(candid[1],ntype(array,i,j,n,m));
            candid[2] = std::max(candid[2],ltype(array,i,j,n,m));
            candid[3] = std::max(candid[3],squaretype(array,i,j,n,m));
            candid[4] = std::max(candid[4],linetype(array,i,j,n,m));
        }
    }
    // for(int i = 0; i < 5; i++){
    //     std::cout<<candid[i]<<std::endl;
    // }
    std::cout<<*std::max_element(candid,candid+5)<<std::endl;
    return 0;
}