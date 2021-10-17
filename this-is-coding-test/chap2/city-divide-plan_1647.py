def find_parent(x):    
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]
def union(x,y):
    a = find_parent(x)
    b = find_parent(y)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

n,m = map(int,input().split())
parent = [i for i in range(n+1)]
e = []
for _ in range(m):
    a,b,cost = map(int,input().split())
    e.append([cost,a,b])
e.sort()

i = 0
result = []


for i in range(m):
    cost,a,b = e[i]
    if find_parent(a) != find_parent(b):            
        result.append(cost)
        union(a,b)
print(sum(result[:-1]))

    

