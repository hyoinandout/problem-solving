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
    print("------------------------------")
    print(phase)
    print(y,x)
    for i in range(4):
        for j in range(4):
            print(space[i][j],end=' ')
        print()
    shark[0] += space[y][x][0]
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
    
    if checkShark(sharkPos,shark[1]-1):
        while 0<= y <4 and 0<= x <4:
            y += directionY[shark[1]-1]
            x += directionX[shark[1]-1]
            answer = max(answer,dfs(y,x,space,shark,phase+1))
    finalAnswer = 0
    finalAnswer += answer
    return finalAnswer


space = [[] for _ in range(4)]
for i in range(4):
    row = list(map(int,input().split()))
    for j in range(4):
        a = row[2*j]
        b = row[2*j + 1]
        space[i].append([a,b])
print(space)
shark = [0,0]
print(dfs(0,0,space,shark,0))



