# 다시 풀어보자
import heapq
def mars(array):
    q = []
    distance = [[987654321] * len(array) for _ in range(len(array))]
    heapq.heappush(q,[array[0][0],0,0])
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    while q:
        dist, x, y = heapq.heappop(q)
        # BFS + 다익스트라
        if dist > distance[y][x]:
            continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= len(array) or ny >= len(array):
                continue
            # 다익스트라
            cost = dist + array[ny][nx]
            if cost < distance[ny][nx]:
                distance[ny][nx] = cost
                heapq.heappush(q,[cost,nx,ny]) 
    return distance[n-1][n-1]


t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(list(map(int,input().split())))
    print(mars(arr))