n = int(input())
a = [[0] * n for _ in range(n)]
for i in range(n):
    a[i] = list(input().split())

def check(a,n,i,j):
    up = True
    down = True
    left = True
    right = True
    for x in range(i-1,-1,-1):
        if a[x][j] == 'S':
            up = False
            break
        elif a[x][j] == 'O':
            up = True
            break
    for x in range(i+1,n):
        if a[x][j] == 'S':
            down = False
            break
        elif a[x][j] == 'O':
            down = True
            break
    for x in range(j-1,-1,-1):
        if a[i][x] == 'S':
            left = False
            break
        elif a[i][x] == 'O':
            left = True
            break
    for x in range(j+1,n):
        if a[i][x] == 'S':
            right = False
            break
        elif a[i][x] == 'O':
            right = True
            break
    return up and down and left and right

def func(a,n):
    k = True
    for i in range(n):
        for j in range(n):
            if a[i][j] == 'T':
                k = k and check(a,n,i,j)
    return k

def obstacle(a,n):
    for i in range(n*n):
        if a[i//n][i%n] == 'X':
            a[i//n][i%n] = 'O'
            for j in range(i+1,n*n):
                if a[j//n][j%n] == 'X':
                    a[j//n][j%n] = 'O'
                    for k in range(j+1,n*n):
                        if a[k//n][k%n] == 'X':
                            a[k//n][k%n] = 'O'
                            if func(a,n):
                                return True
                            a[k//n][k%n] = 'X'
                    a[j//n][j%n] = 'X'
            a[i//n][i%n] = 'X'
    return False

if obstacle(a,n):
    print('YES')
else:
    print('NO')