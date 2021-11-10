import heapq

def find_parent(parent,x):
    if parent[x] != x:
        parent[x] = find_parent(parent,parent[x])
    return parent[x]

def union(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n = int(input())
candid = []
for i in range(1,n+1):
    x,y,z = map(int,input().split())
    candid.append([x,y,z,i])
parent = [i for i in range(n+1)]

sort = [[] for _ in range(3)]
for i in range(3):
    sort[i] = sorted(candid,key=lambda x:x[i])

distance = []
for i in range(3):
    for j in range(n-1):
        localDistance = [abs(sort[i][j+1][i] - sort[i][j][i]),sort[i][j+1][3],sort[i][j][3]]
        heapq.heappush(distance,localDistance)

result = 0
while distance:
    minimalDistance,a,b = heapq.heappop(distance)
    # print(minimalDistance,a,b)
    if find_parent(parent,a) != find_parent(parent,b):
        union(parent,a,b)
        result += minimalDistance
print(result)
# print(parent)
