import sys
input = sys.stdin.readline

#��뵥���͸� 3�������� ����
used=[[[0]*10 for _ in range(9)] for _ in range(9)]
num = [list(map(int, input().split())) for _ in range(9)]
emptyspace = [(i, j) for i in range(9) for j in range(9) if num[i][j]==0]

#����ġ�⸦ ���� Ȯ�� 1. ���� 2. ���� 3. ���簢��
#����,���δ� ���� Ȯ�� ���� ������ ���簢��  
#���� ������ �����ϴ� ���� ����Ʈ �߿� ���ʷ� �����
#���� ������ �ٽ� �ڷ� ��

def fill(count):
    #�������� ��� ��ĭ�� ä������ ��
    if count==len(emptyspace):
        for n in num:
            print(*n)
        exit(0)
    i, j =emptyspace[count]
    #�ʱ�ȭ
    used[i][j]=[0,0,0,0,0,0,0,0,0,0]
    #���μ���
    for k in range(9):
        used[i][j][num[i][k]]=1
        used[i][j][num[k][j]]=1
    #�밢��
    a=i//3
    b=j//3
    for m in range(3):
        for n in range(3):
            used[i][j][num[a*3+m][b*3+n]]=1
        #��Ʈ��ŷ
    for l in range(1, 10):
        if not used[i][j][l]:
            used[i][j][l]=1
            num[i][j]=l
            fill(count+1)
            used[i][j][l]=0
            num[i][j]=0
fill(0)