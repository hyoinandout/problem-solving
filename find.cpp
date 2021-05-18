#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000000];
void bs(int x, int start, int end){
    if(start>end){
        printf("no ");
        return;
    }
    int mid = (start+end)/2;
    if(arr[mid]==x){
        printf("yes ");
        return;
    }
    if(arr[mid]<x){
        bs(x,mid+1,end);
    }
    else{
        bs(x,start,mid-1);
    }
}


int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        bs(x,0,n-1);
    }
}