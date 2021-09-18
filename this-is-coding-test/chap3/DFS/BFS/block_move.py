# 한가지 기준으로 판별해야 오타 같은 것들을 잡아내기 쉽다
# tuple 연산부터 시작
from collections import deque

def comp(tup1,tup2):
    return tup1[0] >= tup2[0] or tup1[1] >= tup2[1]

def comp2(tup2,tup1):
    return tup1[0] > tup2[0] or tup1[1] > tup2[1]

def bfs(board,visited):
    size = len(board)
    q = deque()
    q.append([(1,1),(1,2)])
    visited.append([(1,1),(1,2)])
    cnt = 0
    ji = 0
    while q:
        k = len(q)
        #print(cnt)
        for _ in range(k):
            # if ji == 13:
            #     return 0
            robot = q.popleft()
            a,b = robot[0],robot[1]
            #print("a = " ,a, "b = ",b)
           # print(visited)
            if a == (size-2,size-2) or b == (size-2,size-2):
                return cnt
            dxy = [(-1,0),(1,0),(0,-1),(0,1)]
            # state = 0 일때 horizontal, 1일때 vertical
            rx = [[(0,0),(0,0),(1,1),(-1,1)],[(0,0),(0,0),(1,-1),(1,1)]]
            ry = [[(1,-1),(-1,-1),(0,0),(0,0)],[(-1,-1),(-1,1),(0,0),(0,0)]]

            for i in range(4):
                #print(i,a,b)
                #print(dxy[i])
                nx = (a[0] + dxy[i][0],a[1] + dxy[i][1])
                ny = (b[0] + dxy[i][0],b[1] + dxy[i][1])
                #print("nx = ", nx," ny = ",ny)

                if comp2(nx,(0,0)) or comp2(ny,(0,0)) or comp(nx,(size,size)) or comp(ny,(size,size)):
                    #print("continue")
                    continue
                if board[nx[0]][nx[1]] == 1 or board[ny[0]][ny[1]] == 1:
                    continue
                x = [nx,ny]
                if x not in visited:
                    visited.append(x)
                    #print(x)
                    q.append(x)

            if abs(a[0] - b[0]) == 0:
                for i in range(4):
                    rnx = tuple(sum(elem) for elem in zip(a, rx[0][i]))
                    rny = tuple(sum(elem) for elem in zip(b, ry[0][i]))
                    #print("rnx = ", rnx,"rny = ",rny)
                    if comp2(rnx,(0,0)) or comp2(rny,(0,0)) or comp(rnx,(size,size)) or comp(rny,(size,size)):
                        continue
                    if board[rnx[0]][rnx[1]] == 1 or board[rny[0]][rny[1]] == 1:
                        continue
                    if i == 0:
                        if board[a[0] + 1][a[1] + 1] == 1:
                            #print("continue 0")
                            continue
                    elif i == 1:
                        if board[a[0] - 1][a[1] + 1] == 1:
                            #print("continue 1")
                            continue
                    elif i == 2:
                        if board[a[0] + 1][a[1]] == 1:
                            #print("continue 2")
                            continue
                    elif i == 3:
                        if board[a[0] - 1][a[1]] == 1:
                            #print("continue 3")
                            continue
                    x = [rnx,rny]
                    x.sort()
                    if x not in visited:
                        visited.append(x)
                        #print(x)
                        q.append(x)
                        #print(x)
            else:
                for i in range(4):
                    rnx = tuple(sum(elem) for elem in zip(a, rx[1][i]))
                    rny = tuple(sum(elem) for elem in zip(b, ry[1][i]))
                    if  comp2(rnx,(0,0)) or comp2(rny,(0,0)) or comp(rnx,(size,size)) or comp(rny,(size,size)):
                        continue
                    if board[rnx[0]][rnx[1]] == 1 or board[rny[0]][rny[1]] == 1:
                        continue
                    if i == 0:
                        if board[a[0] + 1][a[1] - 1] == 1:
                            continue
                    elif i == 1:
                        if board[a[0] + 1][a[1] + 1] == 1:
                            continue
                    elif i == 2:
                        if board[b[0] - 1][b[1] - 1] == 1:
                            continue
                    elif i == 3:
                        if board[b[0] - 1][b[1] + 1] == 1:
                            continue
                    x = [rnx,rny]
                    x.sort()
                    if x not in visited:
                        visited.append(x)
                        #print(x)
                        q.append(x)
            #ji+=1
            #print(q)
            #print("Visited ",visited)
        cnt += 1
        for i in visited:
            a,b = i[0],i[1]
            board[a[0]][a[1]]=2
            board[b[0]][b[1]]=2
        for i in range(len(board)):
            print(board[i])
        print(cnt)
        print()
        

def solution(board):
    size = len(board)
    largeBoard = [[1] * (size+2) for _ in range(size+2)]
    for i in range(1,size+1):
        for j in range(1,size+1):
            largeBoard[i][j] = board[i-1][j-1]
    #print(largeBoard)
    visited = []
    for i in range(len(largeBoard)):
        print(largeBoard[i])
    print("\n")
    answer = bfs(largeBoard,visited)
    for i in visited:
        a,b = i[0],i[1]
        largeBoard[a[0]][a[1]]=2
        largeBoard[b[0]][b[1]]=2
    for i in range(len(largeBoard)):
        print(largeBoard[i])
    return answer
print(solution([[0, 0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 1, 1, 0], [0, 1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 1, 1], [0, 0, 1, 0, 0, 0, 0]]))