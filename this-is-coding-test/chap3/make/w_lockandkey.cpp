//1도 모르겠음 : 발표문제
//확장 시킬 생각보단 쪼개서 다 비교대조할 생각을 했음
// 확장이 구현면에선 편함
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotateMatrixBy90Degree(vector<vector<int>> a){
    int n = a.size();
    int m = a[0].size();
    //새로운 문법
    vector<vector<int>> result(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[j][n-i-1]=a[i][j];
        }
    }
    return result;
}

bool check(vector<vector<int>> newLock){
    int lockLength = newLock.size()/3;
    for(int i=lockLength;i<lockLength*2;i++){
        for(int j=lockLength;j<lockLength*2;j++){
            if(newLock[i][j]!=1){
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int m = key.size();
    int n = lock.size();
    
    vector<vector<int>> newLock(n*3,vector<int>(n*3));
    
    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++){
            newLock[i][j] = lock[i-n][j-n];
        }
    }
    
    for(int i=0;i<4;i++){
        key = rotateMatrixBy90Degree(key);
        for(int x=0;x<n*2;x++){
            for(int y=0;y<n*2;y++){
                for(int j=0;j<m;j++){
                    for(int k=0;k<m;k++){
                        newLock[x+j][y+k] += key[j][k];
                    }
                }
                if(check(newLock)) return true;
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++){
                        newLock[x+i][y+j] -= key[i][j];
                    }
                }                
            }
        }
    }
    
    
    
    
    return false;
}