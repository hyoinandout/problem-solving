#include <cstdio>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int sy,sx,dir;
    scanf("%d %d %d",&sy,&sx,&dir);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int cnt=1;
    int check =0;
    while(1){
        arr[sy][sx]=1;
        
        switch (dir)
        {
            case 0: if(arr[sy][sx-1]!=1){
                --sx;
                dir = 3;
                cnt++;
                check=0;
                break;
                }
            case 3: if(arr[sy-1][sx]!=1){
                --sy;
                dir = 2;
                cnt++;
                check=0;
                break;
            }
            case 2: if(arr[sy][sx+1]!=1){
                ++sx;
                dir = 1;
                cnt++;
                check=0;
                break;
            }
            case 1: if(arr[sy+1][sx]!=1){
                ++sy;
                dir = 0;
                cnt++;
                check=0;
                break;
            }
            default:
                dir = 0;
                check++;
                if(check>1){
                    printf("%d",cnt);
                    return 0;
                }
                break;
        }
    }
}