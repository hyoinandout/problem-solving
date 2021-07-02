#include <cstdio>
#include <cstring>



int main(){
    
    //memset(arr,0,sizeof(arr));
    //main에서 segmentation fault 뜨는 이유는 뭘까. int로 바꿔서 빌드하면 main에서 seg fault 오류가 난다.
    int arr[26][200001]={0,};
    for(int i=0;;i++){
        char t = getchar();
        if(t=='\n') break;
        //이 부분에서 틀렸었다. 45프로에서 멈췄었는데 그 이유는 한번 더 반복문을 안써주면 부분합이 안되고 1 0 1 이렇게 될 수 있기 때문이다.
        for(int j=0;j<26;j++)
        arr[j][i+1]=arr[j][i]+(t=='a'+j?1:0);
	for(int j=0;j<26;j++){
		printf("%d ",arr[j][i]);
	}
	printf("\n");
    }

    int q;
    scanf("%d",&q);
   
    for(int i=0;i<q;i++){
        char al;
        int st,en;
        scanf(" %c %d %d",&al ,&st,&en);
        printf("%d\n",arr[al-'a'][en+1]-arr[al-'a'][st]);
    }
    return 0;
}
