tc = int(input())
for _ in range(tc):
    n,m,w = map(int,input().split())
    graph = [[] for _ in range(n+1)]
    # https://www.acmicpc.net/board/view/72995
    dist = [0] * (n+1)
    # dist = [987654321] * (n+1)
    # dist[1] = 0
    for _ in range(m):
        s,e,t = map(int,input().split())
        graph[s].append([e,t])
        graph[e].append([s,t])
    for _ in range(w):
        s,e,t = map(int,input().split())
        graph[s].append([e,-t])
    flag = False
    for k in range(1,n):
        for i in range(1,n+1):
            for j in range(len(graph[i])):
                if dist[i] != 987654321 and dist[graph[i][j][0]] > dist[i] + graph[i][j][1]:
                    dist[graph[i][j][0]] = dist[i] + graph[i][j][1]
                print(dist)
    for i in range(1,n+1):
        for j in range(len(graph[i])):
            if dist[i] != 987654321 and dist[graph[i][j][0]] > dist[i] + graph[i][j][1]:
                flag = True
                dist[graph[i][j][0]] = dist[i] + graph[i][j][1]
                break
    # 시작점이 1이긴 했지만 n번째에서 n이 갱신된다는 보장이 있나?
    if flag:
        print("YES")
    else:
        print("NO")

            

    