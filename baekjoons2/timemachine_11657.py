n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append([b,c])
dist = [987654321] * (n+1)
dist[1] = 0
for i in range(1,n):
    for j in range(1,n+1):
        for k in range(len(graph[j])):
            if dist[j] != 987654321 and dist[graph[j][k][0]] > dist[j] + graph[j][k][1]:
                dist[graph[j][k][0]] = dist[j] + graph[j][k][1]
flag = False
for j in range(1,n+1):
    for k in range(len(graph[j])):
        if dist[j] != 987654321 and dist[graph[j][k][0]] > dist[j] + graph[j][k][1]:
            dist[graph[j][k][0]] = dist[j] + graph[j][k][1]
            flag = True
if flag:
    print(-1)
else:
    for i in range(2,n+1):
        if dist[i] == 987654321:
            print(-1)
        else:
            print(dist[i])
    