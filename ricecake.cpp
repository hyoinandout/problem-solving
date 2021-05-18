#include <cstdio>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+= arr[i];
    }
    int start=0,end=sum;
    sum=0;
    while(start<=end){
        int mid = (start+end)/2;
        for(int i=0;i<n;i++){
            if(arr[i]>=mid){
                sum+=arr[i]-mid;
            }
        }
        if(sum>=m){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        sum=0;
    }
    printf("%d",end);
}