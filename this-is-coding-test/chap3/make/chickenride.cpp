//조합 구현
//나는 순열 조합 중복조합 등 경우의수 구현에 약한 것 같다

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
vector<vector<int>> chickDistanceEach;
// vector<vector<int>> combination;

void comb (int numb, int idx){
    // if(idx > m){
    //     for(int i=0;i<m;i++){
    //         combination.push_back
    //     }
    // }
}

vector<int> chickDistance(pair<int,int> a){
    vector<int> itsChickenDistance;
    for(int i=0;i<house.size();i++){
        int xdista = house[i].first - a.first;
        int ydista = house[i].second - a.second;
        if(xdista<0) xdista = -xdista;
        if(ydista<0) ydista = -ydista;

        int chickenDistance = xdista+ydista;

        itsChickenDistance.push_back(chickenDistance);
    }
    return itsChickenDistance;
}

int combination(int whichHouse){
    int result = 101;
    
    return result;
}

int main(){
    scanf("%d %d",&n,&m);
    int type;
    // vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %d",&type);
            if(type == 1){
                house.push_back({i,j});
            }else if(type ==2){
                chicken.push_back({i,j});
            }
        }
    }   
    
    for(int i=0;i<chicken.size();i++){
        chickDistanceEach.push_back(chickDistance(chicken[i]));
    }

    vector<bool> binary(chicken.size());
    fill(binary.end()-m,binary.end(), true);
    
    int result = 1e9;
    do{
        int temp = 0;
        for(int i=0;i<house.size();i++){
            int a = 1e9;
            for(int j=0;j<chicken.size();j++){
                if(binary[j]){
                  a = min(a,chickDistanceEach[j][i]);
                }       
            }
            temp += a;
        }
        result = min(result, temp);
    }while(next_permutation(binary.begin(),binary.end()));

    printf("%d\n", result);
    return 0;
}