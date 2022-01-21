import sys
input = sys.stdin.readline

#사용데이터를 3차원으로 저장
used=[[[0]*10 for _ in range(9)] for _ in range(9)]
num = [list(map(int, input().split())) for _ in range(9)]
emptyspace = [(i, j) for i in range(9) for j in range(9) if num[i][j]==0]

#가지치기를 통해 확인 1. 가로 2. 세로 3. 정사각형
#가로,세로는 쉽게 확인 가능 문제는 정사각형  
#앞의 조건을 만족하는 숫자 리스트 중에 차례로 집어보기
#맞지 않으면 다시 뒤로 백

def fill(count):
    #종료조건 모든 빈칸이 채워졌을 때
    if count==len(emptyspace):
        for n in num:
            print(*n)
        exit(0)
    i, j =emptyspace[count]
    #초기화
    used[i][j]=[0,0,0,0,0,0,0,0,0,0]
    #가로세로
    for k in range(9):
        used[i][j][num[i][k]]=1
        used[i][j][num[k][j]]=1
    #대각선
    a=i//3
    b=j//3
    for m in range(3):
        for n in range(3):
            used[i][j][num[a*3+m][b*3+n]]=1
        #백트래킹
    for l in range(1, 10):
        if not used[i][j][l]:
            used[i][j][l]=1
            num[i][j]=l
            fill(count+1)
            used[i][j][l]=0
            num[i][j]=0
fill(0)