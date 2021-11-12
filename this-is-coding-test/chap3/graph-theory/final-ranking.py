from collections import deque
t = int(input())

for _ in range(t):
    n = int(input())
    ranking = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for i in range(len(ranking)):
        for j in range(i+1,len(ranking)):
            graph[ranking[j]].append(ranking[i])
    m = int(input())
    for _ in range(m):
        a,b = map(int,input().split())
        if b in graph[a]:
            graph[a].remove(b)
            graph[b].append(a)
        elif a in graph[b]:
            graph[b].remove(a)
            graph[a].append(b)
    #print(graph)
    q = deque()
    for i in range(1,len(graph)):
        if len(graph[i]) == 0:
            q.append(i)
    result = []
    while q:
        node = q.popleft()
        for i in range(1,len(graph)):
            if node in graph[i]:
                graph[i].remove(node)
                if len(graph[i]) == 0:
                    q.append(i)
        result.append(node)
    
    if len(result) != n:
        print("IMPOSSIBLE")
    else:
        for i in range(len(result)):
            print(result[i],end = ' ')
        print()
    
