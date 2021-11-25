# 백트래킹 구현
# 이 때 재귀함수 인자가 local 하게 적용되는지 아니면 global하게 적용되는지 알아서 정리할 것!
# https://andamiro25.tistory.com/96 : 가변적 개체/ 불가변적 개체 
import copy
directionY = [-1,-1,0,1,1,1,0,-1]
directionX = [0,-1,-1,-1,0,1,1,1]

def checkFish(i,j,direction,space,sharkPos):
    checkI = i + directionY[direction]
    checkJ = j + directionX[direction]
    cnt = 0
    while True:
        if (checkI == sharkPos[0] and checkJ == sharkPos[1]) or (checkI >= 4) or (checkJ >= 4) or (checkI < 0) or (checkJ < 0):
            cnt += 1
            direction += 1
            direction %= 8
            checkI = i + directionY[direction]
            checkJ = j + directionX[direction]
            if cnt > 8:
                return
        else:
            space[i][j][1] = direction+1
            space[checkI][checkJ],space[i][j] = space[i][j],space[checkI][checkJ]
            return

def checkShark(sharkPos,direction):
    checkI = sharkPos[0] + directionY[direction]
    checkJ = sharkPos[1] + directionX[direction]
    if (checkI >= 4) or (checkJ >= 4) or (checkI < 0) or (checkJ < 0):
        return False
    return True

def dfs(y,x,space,shark,phase):
    answer = 0
    shark[0] = space[y][x][0]
    shark[1] = space[y][x][1]
    space[y][x] = [0,0]
    sharkPos = [y,x]
    for k in range(1,17):
        flag = False
        for i in range(4):
            for j in range(4):
                if space[i][j][0] == k:
                    checkFish(i,j,space[i][j][1]-1,space,sharkPos)
                    flag = True
                    break
            if flag:
                break
    # print("------------------------------")
    # print(phase)
    # for i in range(4):
    #     for j in range(4):
    #         print(space[i][j],end=' ')
    #     print()
    # print("------------------------------")
    ny = y
    nx = x
    if checkShark(sharkPos,shark[1]-1):
        while True:
            ny += directionY[shark[1]-1]
            nx += directionX[shark[1]-1]
            #print(ny,nx,shark[1],phase)
            
            if 0<= ny and ny <4 and 0<= nx and nx <4:
                if  space[ny][nx][0] == 0:
                    continue
                # 펀치라인
                sharkCp = copy.deepcopy(shark)
                print(sharkCp)
                arr = copy.deepcopy(space)
                answer = max(answer,dfs(ny,nx,arr,sharkCp,phase+1))
            else:
                break
    return shark[0] + answer


space = [[] for _ in range(4)]
for i in range(4):
    row = list(map(int,input().split()))
    for j in range(4):
        a = row[2*j]
        b = row[2*j + 1]
        space[i].append([a,b])
#print(space)
shark = [0,0]
print(dfs(0,0,space,shark,0))



