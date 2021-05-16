#include <cstdio>

int n;
int arr[1000][3];


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=1;i<n;i++){
        arr[i][0]+=(arr[i-1][1]>arr[i-1][2]?arr[i-1][2]:arr[i-1][1]);
        arr[i][1]+=(arr[i-1][0]>arr[i-1][2]?arr[i-1][2]:arr[i-1][0]);
        arr[i][2]+=(arr[i-1][1]>arr[i-1][0]?arr[i-1][0]:arr[i-1][1]);
    }
    printf("%d",(arr[n-1][0]>arr[n-1][1]?arr[n-1][1]:arr[n-1][0])>arr[n-1][2]?arr[n-1][2]:(arr[n-1][0]>arr[n-1][1]?arr[n-1][1]:arr[n-1][0]));
    return 0;
}