//수의 범위를 고려해서 최소한의 연산, 또한 재귀함수를 사용할때 같은 값이 있다면 저장해놓고 사용하는 것이
//재귀함수가 호출되는 횟수를 줄여준다.
#include <cstdio>
long long int a,b,c;
long long int fn(long long int x, long long int y, long long int z){
    if(y==0) return 1;
    long long int n = (fn(x,y/2,z));
    if(y%2==0) return (n*n)%z;
    else return (x*((n*n)%z))%z;
}
int main(){
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld",fn(a,b,c));
    return 0;
}