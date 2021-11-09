import heapq

def find_parent(parent,a):
    if parent[a] != a:
        parent[a] = find_parent(parent,parent[a])
    return parent[a]

def union(parent,a,b):
    _a  = find_parent(parent,a)
    _b  = find_parent(parent,b)
    if _a < _b:
        parent[_b] = _a
    else:
        parent[_a] = _b

n,m =map(int,input().split())

# graph = [[] for _ in range(n)]
q = []
parent = [i for i in range(n)]
sum = 0
for _ in range(m):
    x,y,z = map(int,input().split())
    heapq.heappush(q,[z,x,y])
    # graph[x].append([y,z])
    sum += z

result = 0
while q:
    cost,x,y = heapq.heappop(q)
    if find_parent(parent,x) == find_parent(parent,y):
        continue
    union(parent,x,y)
    result += cost

print(sum - result)

