# indegree, 인접행렬, cycle이나 모호함 발생할 때 생각못했었음
from collections import deque
t = int(input())

for _ in range(t):
    n = int(input())
    ranking = list(map(int,input().split()))

    #graph = [[] for _ in range(n+1)]
    indegree = [0] * (n+1)
    graph = [[False] * (n+1) for _ in range(n+1)]

    for i in range(len(ranking)):
        for j in range(i+1,len(ranking)):
            #graph[ranking[j]].append(ranking[i])
            graph[ranking[i]][ranking[j]] = True
            indegree[ranking[j]] += 1
    m = int(input())
    for _ in range(m):
        a,b = map(int,input().split())
        # if b in graph[a]:
        #     graph[a].remove(b)
        #     graph[b].append(a)
        # elif a in graph[b]:
        #     graph[b].remove(a)
        #     graph[a].append(b)
        if graph[a][b]:
            graph[a][b] = False
            graph[b][a] = True
            indegree[a] += 1
            indegree[b] -= 1
        else:
            graph[a][b] = True
            graph[b][a] = False
            indegree[a] -= 1
            indegree[b] += 1
    #print(graph)
    q = deque()
    result = []

    for i in range(1,n+1):
        if indegree[i] == 0:
            q.append(i)

    certain = True
    cycle = False

    # for i in range(1,len(graph)):
    #     if len(graph[i]) == 0:
    #         q.append(i)

    for i in range(n):
        if len(q) == 0:
            cycle = True
            break
        if len(q) >= 2:
            certain = False
            break
        now = q.popleft()
        result.append(now)
        for j in range(1,n+1):
            if graph[now][j]:
                indegree[j] -= 1
                if indegree[j] == 0:
                    q.append(j)
    
    # while q:
    #     node = q.popleft()
    #     for i in range(1,len(graph)):
    #         if node in graph[i]:
    #             graph[i].remove(node)
    #             if len(graph[i]) == 0:
    #                 q.append(i)
    #     result.append(node)
    
    # if len(result) != n:
    #     print("IMPOSSIBLE")
    # else:
    #     for i in range(len(result)):
    #         print(result[i],end = ' ')
    #     print()

    if cycle:
        print("IMPOSSIBLE")
    elif not certain:
        print("?")
    else:
        for i in result:
            print(i, end= ' ')
        print()
    
