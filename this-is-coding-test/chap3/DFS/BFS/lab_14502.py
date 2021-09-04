from collections import deque

def bfs(i,j,d,n,m):
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    q = deque()
    q.append((i,j))
    while q:
        y,x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if nx < 0 or ny < 0 or nx >= m or ny >= n:
                continue
            if d[ny][nx] == 0:
                d[ny][nx] = 2
                q.append((ny,nx))

def virus(i,j,k,b,n,m):
    c = []
    c = b.copy()
    c[i//m][i%m] = 1
    c[j//m][j%m] = 1
    c[k//m][k%m] = 1
    for i in range(n):
        for j in range(m):
            if c[i][j] == 2:
                bfs(i,j,c,n,m)
    cnt = 0
    for i in range(n):
        for j in range(m):
            if(c[i][j] == 0):
                cnt += 1
    return cnt

n,m = map(int,input().split())
a = [[0] * m for _ in range(n)]
for i in range(n):
    a[i] = list(map(int,input().split()))
print(a)
result = 0
size = n*m
for i in range(size):
    if a[i//m][i%m] == 1 or a[i//m][i%m] == 2:
        continue
    for j in range(i+1,size):
        if a[j//m][j%m] == 1 or a[j//m][j%m] == 2:
            continue
        for k in range(j+1,size):
            if a[k//m][k%m] == 1 or a[k//m][k%m] == 2:
                continue
            result = max((result, virus(i,j,k,a,n,m)))
print(a)
print(result)