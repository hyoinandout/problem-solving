# queue라고 해도 worstcase 가 2500억이다.
import sys
from collections import deque

n,m = map(int,sys.stdin.readline().rstrip().split())
arr = [[0] * m for _ in range(n)]
for i in range(n):
    a = sys.stdin.readline().rstrip()
    for j in range(m):
        arr[i][j] = int(a[j])

def bfs(board,i,j):
    q = deque()
    visited = [[[False for _ in range(2)] for _ in range(m)] for _ in range(n)]
    q.append([i,j,0])
    visited[i][j][0] = True
    dy = [0,0,-1,1]
    dx = [-1,1,0,0]
    cnt = 1
    result = (n*m) + 1
    while q:
        size = len(q)
        for _ in range(size):
            y,x,crashed = q.popleft()
            if y == n-1 and x == m-1:
                result = min(result,cnt)
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or nx < 0 or ny >= n or nx >= m:
                    continue
                if crashed == 0 and visited[ny][nx][0] == False:
                    if board[ny][nx] == 0:
                        q.append([ny,nx,0])
                        visited[ny][nx][0] = True
                    else:
                        q.append([ny,nx,1])
                        visited[ny][nx][1] = True
                else:
                    if board[ny][nx] == 0 and visited[ny][nx][1] == False:
                        q.append([ny,nx,1])
                        visited[ny][nx][1] = True
        cnt += 1
    return result

answer = (n * m) + 1
answer = min(answer,bfs(arr,0,0))
    
if answer == ((n * m) + 1):
    print(-1)
else:
    print(answer)


