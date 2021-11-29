# 상어 번호 = 1234, 방향 번호 = 1234
# 1,2,3,4 = 위, 아래, 왼쪽, 오른쪽
from collections import deque
import copy
def debugPrint(grid,sharkDir,prefer,footprint1,ongoing):
    print(grid)

    print()

    print(sharkDir)

    print()

    for i in range(1,m+1):
        for j in range(1,5):
            for z in range(1,5):
                print(prefer[i][j][z],end= ' ')
        print()
    
    print()

    for i in range(n):
        for j in range(n):
            print(footprint1[i][j], end= ' ')
        print()


    print()

    for i in range(n):
        for j in range(n):
            print(ongoing[i][j], end= ' ')
        print()

n,m,k = map(int,input().split())

grid = []
for _ in range(n):
    grid.append(list(map(int,input().split())))
    
sharkDir = [0] + list(map(int,input().split()))

prefer = [[0] * 5 for _ in range(m+1)]
for i in range(1,m+1):
    for j in range(1,5):
        prefer[i][j]= [0] + list(map(int,input().split()))

# footprint1[0] : 시간, footprint1[1] : 번호
footprint = [[[0 for _ in range(2)] for _ in range(n)] for _ in range(n)]
footprint1 = [[[0 for _ in range(2)] for _ in range(n)] for _ in range(n)] 
# ongoing[0] : 방향, ongoing[1] : 번호
ongoing = [[0 for _ in range(n)] for _ in range(n)] 

q = deque()
for i in range(n):
    for j in range(n):
        if grid[i][j] != 0:
            footprint1[i][j][0] = k
            footprint1[i][j][1] = grid[i][j]
            ongoing[i][j] = grid[i][j]
            q.append([sharkDir[grid[i][j]],i,j,grid[i][j]])

#debugPrint(grid,sharkDir,prefer,footprint1,ongoing)

dy = [0,-1,1,0,0]
dx = [0,0,0,-1,1]

time = 0
# q = 방향, 포지션y, 포지션x, 번호
while q and time <= 1000:
    time += 1
    footprint = copy.deepcopy(footprint1)
    size = len(q)
    for i in range(n):
        for j in range(n):
            if footprint1[i][j][1] != 0 :
                footprint1[i][j][0] -= 1
    cnt = 0
    for i in range(size):
        flag = True
        dir,nowi,nowj,num = q.popleft()
        if time == 4 and nowi == 1:
            pass
        if ongoing[nowi][nowj] != num:
            continue
        for z in range(1,5):
            nextDir = prefer[num][dir][z]
            y = nowi + dy[nextDir]
            x = nowj + dx[nextDir]
            if y < 0 or x < 0 or y >= n or x >= n or (0 < footprint1[y][x][0] and footprint1[y][x][0] < k and footprint1[y][x][1] != num and time >= 1) or (footprint1[y][x][0] == 0 and footprint1[y][x][1] != 0):
                continue
            if (footprint1[y][x][1] != 0 and footprint1[y][x][1] > num and footprint1[y][x][0] == k) or footprint1[y][x][1] == 0:
                q.append([nextDir,y,x,num])
                footprint1[y][x][0] = k
                footprint1[y][x][1] = num
                ongoing[nowi][nowj] = 0
                ongoing[y][x] = num
                flag = False
                break
            if (footprint1[y][x][0] == k):
                ongoing[nowi][nowj] = 0
                flag = False
                break
        if flag:
            for z in range(1,5):
                nextDir = prefer[num][dir][z]
                y = nowi + dy[nextDir]
                x = nowj + dx[nextDir]
                if y < 0 or x < 0 or y >= n or x >= n or (0 < footprint1[y][x][0] and footprint1[y][x][0] < k and footprint1[y][x][1] != num and time >= 1):
                    continue
                if footprint1[y][x][1] == num:
                    q.append([nextDir,y,x,num])
                    footprint1[y][x][0] = k
                    footprint1[y][x][1] = num
                    ongoing[nowi][nowj] = 0
                    ongoing[y][x] = num
                    break

    for i in range(n):
        for j in range(n):
            if footprint1[i][j][0] == 0 :
                footprint1[i][j][1] = 0    
        # for i in range(n):
        #     for j in range(n):
        #         if ongoing[i][j][1] != 0:
        #             for k in range(1,5):
        #                 nextDir = prefer[ongoing[i][j][1]][ongoing[i][j][0]][k]
        #                 y = i + dy[nextDir]
        #                 x = j + dx[nextDir]
        #                 if y < 0 or x < 0 or y >= n or x >= n or (footprint1[y][x][1] != 0 and footprint1[y][x][1] != footprint1[i][j][1]):
        #                     continue
        #                 if (ongoing[y][x][1] != 0 and ongoing[y][x][1] > ongoing[i][j][1]) or ongoing[y][x][1] == 0:
        #                     ongoing[y][x][0] = nextDir
        #                     ongoing[y][x][1] = ongoing[i][j][1]
        #                     footprint1[y][x][0] = k
        #                     footprint1[y][x][1] = ongoing[i][j][1]      
        #                     ongoing[i][j][0] = 0
        #                     ongoing[i][j][1] = 0
        #                     break
    for i in range(n):
        for j in range(n):
            if ongoing[i][j] != 0:
                cnt += 1
    if time == 7:
        print("time 7")
        debugPrint(grid,sharkDir,prefer,footprint1,ongoing)                                
    if time == 8:
        print("time 8")
        debugPrint(grid,sharkDir,prefer,footprint1,ongoing)
    if cnt == 1:
        break
if time <= 1000:
    print(time)
else:
    print(-1)


