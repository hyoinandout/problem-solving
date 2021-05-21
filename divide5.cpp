#include <cstdio>

int main(){
    int x;
    scanf("%d",&x);
    int arr[x+1];
    arr[1]=0;arr[2]=1;arr[3]=1;arr[4]=2;arr[5]=1;
    for(int i=6;i<=x;i++){
        if(i%5==0){
            arr[i] = arr[i/5]+1;
        }
        else if(i%3==0){
            arr[i] = arr[i/3]+1;
        }
        else if(i%2==0){
            if(arr[i/2]<arr[i-1]){
                arr[i] = arr[i/2]+1;
            }
            else{
                arr[i] = arr[i-1]+1;
            }
        }
        else{
                arr[i] = arr[i-1]+1;
            }
    }
    printf("%d",arr[x]);
    return 0;
}