import heapq

n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append([b,1])
    graph[b].append([a,1])

def dijkstra(start):
    q = []
    distance = [987654321] * (n+1)
    distance[start] = 0
    heapq.heappush(q,[0,start])
    while q:
        dist, x = heapq.heappop(q)
        for i in graph[x]:
            cost = dist + i[1]
            if cost > distance[i[0]]:
                continue
            distance[i[0]] = cost
            heapq.heappush(q,[cost,i[0]])
    result = max(distance[1:])
    print(distance.index(result),end= ' ')
    print(result, end= ' ')
    print(distance.count(result))


dijkstra(1)