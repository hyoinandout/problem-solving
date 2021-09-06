from collections import deque

n,k = map(int,input().split())
a = [[0] * n for _ in range(n)]
for i in range(n):
    a[i] = list(map(int,input().split()))
s,x,y = map(int,input().split())

def bfs(a,n,k):
    q = list()
    for i in range(n):
        for j in range(n):
            if a[i][j] != 0:
                q.append((a[i][j],i,j))
    q.sort()
    q = deque(q)
    cnt = 0
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    while q:
        size = len(q)
        for _ in range(size):
            value, y, x = q.popleft()
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or nx < 0 or ny >= n or nx >= n:
                    continue
                if a[ny][nx] == 0:
                    a[ny][nx] = value
                    q.append((value,ny,nx))
        cnt+=1
        if cnt == k:
            return
bfs(a,n,s)
print(a)
print(a[x-1][y-1])