#include <stdio.h>
#include <string>

/*
    1 : 1
    11 : 11
    111 : 1, 3, 37, 111
    1111 : 1, 11, 101, 1111
    11111 : 1, 41, 271, 11111
    111111 : 1, 3, 7, 11, 13, 21
    1111111
*/
int main()
{
    int a;
    while(scanf("%d",&a) == 1){
        // std::string one = "1";
        // while(1){
        //     size_t sz;
        //     long long k = std::stoll(one,&sz,10);
        //     if(k % a == 0){
        //         printf("%d",sz);
        //         break;
        //     }else{
        //         one += "1";
        //     }
        // }
        long long b = 1;
        int i = 1;
        if(a == 1){
            printf("1\n");
            break;
        }
        while((b * 10 + 1) % a)
        {
            b = (b * 10 + 1) % a;
            i += 1;
        }
        printf("%d\n",i+1);
    }
    return 0;
}