import heapq

n,e = map(int,input().split())
start = int(input())
graph=[[] for _ in range(n+1)]
distance = [987654321] * (n+1)
visited = [False] * (n+1)
for _ in range(e):
    u,v,w = map(int,input().split())
    graph[u].append([w,v])
#print(graph)

q = []
heapq.heappush(q,[0,start])
#print(q)
while q:
    dist, dest = heapq.heappop(q)
    if visited[dest]:
        continue
    visited[dest] = True
    if distance[dest] > dist:
        distance[dest] = dist
    for i in range(len(graph[dest])):
        heapq.heappush(q,[graph[dest][i][0] + dist,graph[dest][i][1]])

for i in range(1,n+1):
    if distance[i] == 987654321:
        print("INF")
    else:
        print(distance[i])