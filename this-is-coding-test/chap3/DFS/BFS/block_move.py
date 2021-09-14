from collections import deque

def bfs(board,visited):
    size = len(board)
    q = deque()
    q.append([(0,0),(0,1)])
    cnt = 0
    while q:
        for _ in range(len(q)):
            robot = q.popleft()
            a,b = robot[0],robot[1]
            if a == (size-1,size-1) or b == (size-1,size-1):
                return cnt
            dxy = [(-1,0),(1,0),(0,-1),(0,1)]
            # state = 0 일때 horizontal, 1일때 vertical
            rx = [[(0,0),(0,0),(1,1),(-1,1)],[(0,0),(0,0),(1,-1),(1,1)]]
            ry = [[(1,-1),(-1,-1),(0,0),(0,0)],[(-1,-1),(-1,1),(0,0),(0,0)]]

            for i in range(4):
                nx = a + dxy[i]
                ny = b + dxy[i]
                if nx < 0 or ny < 0 or nx >= size or ny >= size or board[nx[0]][nx[1]] == '1' or board[ny[0]][ny[1]] == '1':
                    continue
                if not (visited[nx[0]][nx[1]] and visited[ny[0]][ny[1]]):
                    visited[nx[0]][nx[1]] = True
                    visited[ny[0]][ny[1]] = True
                    a = [(nx[0],nx[1]),(ny[0],ny[1])]
                    q.append(a)

            if abs(a[0] - b[0]) == 0:
                for i in range(4):
                    rnx = a + rx[0][i]
                    rny = b + ry[0][i]
                    if  rnx < 0 or rny < 0 or rnx >= size or rny >= size or board[rnx[0]][rnx[1]] == '1' or board[rny[0]][rny[1]] == '1':
                        continue
                    if i == 0:
                        if board[a[0] + 1][a[1] + 1] == 1:
                            continue
                    elif i == 1:
                        if board[a[0] - 1][a[1] - 1] == 1:
                            continue
                    elif i == 2:
                        if board[b[0] - 1][b[0] + 1] == 1:
                            continue
                    else:
                        if board[b[0] - 1][b[0] - 1] == 1:
                            continue
                    if not (visited[rnx[0]][rnx[1]] and visited[rny[0]][rny[1]]):
                        visited[rnx[0]][rnx[1]] = True
                        visited[rny[0]][rny[1]] = True
                        a = [(rnx[0],rnx[1]),(rny[0],rny[1])]
                        a.sort()
                        q.append(a)
            else:
                for i in range(4):
                    rnx = a + rx[1][i]
                    rny = b + ry[1][i]
                    if  rnx < 0 or rny < 0 or rnx >= size or rny >= size or board[rnx[0]][rnx[1]] == '1' or board[rny[0]][rny[1]] == '1':
                        continue
                    if i == 0:
                        if board[a[0] + 1][a[1] - 1] == 1:
                            continue
                    elif i == 1:
                        if board[a[0] + 1][a[1] + 1] == 1:
                            continue
                    elif i == 2:
                        if board[b[0] - 1][b[0] - 1] == 1:
                            continue
                    else:
                        if board[b[0] - 1][b[0] + 1] == 1:
                            continue
                    if not (visited[rnx[0]][rnx[1]] and visited[rny[0]][rny[1]]):
                        visited[rnx[0]][rnx[1]] = True
                        visited[rny[0]][rny[1]] = True
                        a = [(rnx[0],rnx[1]),(rny[0],rny[1])]
                        a.sort()
                        q.append(a)
        cnt += 1

def solution(board):
    size = len(board)
    visited = [[False] * (size) for _ in range(size)]
    answer = bfs(board,visited)
    print(answer)
    return answer
solution([[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]])