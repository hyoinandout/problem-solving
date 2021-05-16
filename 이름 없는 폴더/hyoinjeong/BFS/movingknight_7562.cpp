    #include <queue>
    #include <iostream>
    #include <algorithm>
    #include <cstring>



    using namespace std;

    int T,I;
    bool visited[300][300];

    int dx[8]={2,1,-1,-2,-2,-1,1,2};
    int dy[8]={1,2,2,1,-1,-2,-2,-1};

    void bfs(int x, int y, int fx, int fy){
        queue<pair<int,int>> xy;
        xy.push({x,y});
        visited[x][y]=true;
        int level=0;
        bool pandog=true;
        while(!xy.empty()&&pandog){
            if(xy.front().first==fx&&xy.front().second==fy){
                //cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<level<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<level<<endl;
                break;
            }
            level++;
            //cout<<"------ level "<<level<<" ------"<<endl;
            int qsize = xy.size();
            for(int i=0;i<qsize;i++){
                for(int j=0;j<8;j++){
                    int nx = xy.front().first+dx[j];
                    int ny = xy.front().second+dy[j];
                    if(nx<0||ny<0||nx>=I||ny>=I) continue;
                    if(!visited[nx][ny]){
                        //cout<<"nx "<<nx<<" ny "<<ny<<endl;
                        xy.push({nx,ny});
                        visited[nx][ny]=true;
                        if(nx==fx&&ny==fy){
                            //cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<level<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                            cout<<level<<endl;
                            pandog=false;
                            break;
                        }
                    }
                }
                xy.pop();
            }        
        }
    }
    int main(){
        cin>>T;
        for(int i=0;i<T;i++){
            memset(visited,0,sizeof(visited));
            cin>>I;
            int xs,ys,xf,yf;
            cin>>xs>>ys>>xf>>yf;
            bfs(xs,ys,xf,yf);
        }
        return 0;
    }