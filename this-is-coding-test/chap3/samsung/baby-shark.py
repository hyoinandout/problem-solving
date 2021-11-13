# 구현 세부사항 조심 + 2사분면 우선순위 있을 시 완전탐색!
from collections import deque
def bfs(y,x, sharkSize,q, ate):
    localq = deque()
    visit = [[False] * n for _ in range(n)]
    localq.append([y,x])
    candid = []
    cnt = 0
    while localq:
        for _ in range(len(localq)):
            y,x = localq.popleft()
            visit[y][x] = True
            dy = [-1,0,0,1]
            dx = [0,-1,1,0]
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or nx < 0 or ny >= n or nx >= n:
                    continue
                if not visit[ny][nx] and sharkSize >= space[ny][nx]:
                    localq.append([ny,nx])
                    visit[ny][nx] = True
                    if 0 < space[ny][nx] < sharkSize and not ate[ny][nx]:
                        #print(ny,nx)
                        candid.append([ny,nx])
        cnt += 1
        #print("count=",cnt)
        if len(candid) > 0:
            candid.sort()
            #print(candid[0])
            q.append(candid[0])
            return cnt
    return 0


n = int(input())

space = []
q = deque()
ate = [[False] * n for _ in range(n)]
for i in range(n):
    space.append(list(map(int,input().split())))
    for j in range(n):
        if space[i][j] == 9:
            space[i][j] = 0
            q.append([i,j])
            startY = i
            startX = j
sharkSize = 2
time = 0
cnt = -1
while q:
    y,x = q.popleft()
    ate[y][x] = True 
    #print(y,x)
    if space[y][x] < sharkSize:
        cnt += 1
    # time += abs(startY-y)
    # time += abs(startX-x)
    # startY = y
    # startX = x
    if cnt == sharkSize:
        sharkSize += 1
        #print("SharkSize = ", sharkSize)
        cnt = 0
    time += bfs(y,x,sharkSize,q,ate)
print(time)