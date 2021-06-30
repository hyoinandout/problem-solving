//중복순열 어떻게 처리할 것인가
#include <bits/stdc++.h>
using namespace std;
// int n;
// int arr[1000];
// int bumwee[1000000000];
// void cmm(int a){
//     if(a==n){
//         return;
//     }   
    
    
// }
// int main(){
    
//     scanf("%d",&n);
    
//     int result=2;
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//         result+=arr[i];
//     }
//     sort(arr,arr+n);
//     cmm(0);
//     for(int i=1;i<=result;i++){
//         if(bumwee[i]==0){
//             printf("%d",i);
//             return 0;
//         }
//     }


// }

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int target =1;
    for(int i=0;i<n;i++){
        if(target<arr[i]) break;
        target+=arr[i];
    }
    printf("%d",target);
}