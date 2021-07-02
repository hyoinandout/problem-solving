#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<225;i++){
        for(int j=0;j<225;j++){
            for(int k=0;k<225;k++){
                for(int l=0;l<225;l++){
                    if(n==(i*i+j*j+k*k+l*l)){
                        if(i==0){
                            if(j==0){
                                if(k==0){
                                    printf("1");
                                    return 0;
                                }
                                else{
                                    printf("2");
                                    return 0;
                                }
                            }
                            else{
                                printf("3");
                                return 0;
                            }
                        }
                        else{
                            printf("4");
                            return 0;
                        }
                    }
                }
            }
        }
    }
}