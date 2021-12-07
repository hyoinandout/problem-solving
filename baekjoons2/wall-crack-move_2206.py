# queue라고 해도 worstcase 가 2500억이다.
# 벽을 안 부수고도 현재 칸까지 도달이 가능하지만, 벽을 부수고 오는 것이 더 짧다고 가정해봅시다. 현재 지점에서 목표 지점까지 가려면 무조건 벽을 한 개 부숴야만 된다고 해봅시다. 비록 현재 칸까지는 벽을 부수고 오는 것이 최적이었지만, 이 상태로는 끝에 아예 도달을 못 하죠? 현재 칸까지는 더 멀더라도 벽을 안 부수고 와야, 끝에 도달이 가능하죠.
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
                if crashed == 0:
                    if visited[ny][nx][0] == False:
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