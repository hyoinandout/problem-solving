from collections import deque

n,l,r = map(int,input().split())
a = []
for i in range(n):
    a.append(list(map(int,input().split())))
size = len(a)

def bfs(a,i,j,l,r,visited,size):
    if visited[i][j] == True:
        return 1
    q = deque()
    q.append((i,j))
    cnt = 1
    result = a[i][j]
    change = []
    visited[i][j] = True
    change.append((i,j))
    while len(q) != 0:        
        for _ in range(len(q)):
            dy = [-1,1,0,0]
            dx = [0,0,-1,1]
            y,x = q.popleft()
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny<0 or nx<0 or ny >= size or nx >= size:
                    continue
                if l<=abs(a[ny][nx] - a[y][x])<=r and visited[ny][nx] == False:
                    #print(ny,nx)
                    visited[ny][nx] = True
                    cnt +=1
                    result += a[ny][nx]
                    change.append((ny,nx))
                    q.append((ny,nx))
    for i,j in change:
        #print(i,j,result,cnt)
        a[i][j] = result // cnt
    return cnt

def func(a,l,r,size):
    days = 0
    while True:
        visited = [[False] * n for _ in range(size)]
        k = 0
        for i in range(size):
            for j in range(size):
                k += bfs(a,i,j,l,r,visited,size)
        #print(a)
        if k == size * size:
            return days
        days += 1

print(func(a,l,r,size))