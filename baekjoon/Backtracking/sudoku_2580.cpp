#include <iostream>
#include <vector>

using namespace std;

bool pandog = false;
int sudoku[9][9];
int cnt = 0;
vector<pair<int,int>> vec;

bool check(int y, int x, int num){
    for(int i=0;i<9;i++){
        if(sudoku[y][i]==num&&i!=x)
            return false;
        if(sudoku[i][x]==num&&i!=y)
            return false;
    }
    int dy = y/3;
    int dx = x/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[dy*3+i][dx*3+j]==num)
            {
                if((dy*3+i)!=y&&(dx*3+j)!=x)
                    return false;
            }
                
        }
    }
    return true;
}

void bt(int i){
    if(i==vec.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        pandog=true;
        return;
    }
    int y = vec[i].first;
    int x = vec[i].second;
    for(int j=1;j<=9;j++){
        sudoku[y][x]=j;
        if(check(y,x,j)){
            bt(i+1);
        }
        if(pandog)
            return;
    }
    sudoku[y][x]=0;
    return;
}


int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0)
                vec.push_back({i,j});
        }
    }
    //cout<<endl;
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
    // }
    //cout<<endl;
    bt(0);
   // cout<<endl;
    return 0;
}