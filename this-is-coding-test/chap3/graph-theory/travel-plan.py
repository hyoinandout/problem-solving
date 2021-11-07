n,m = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))
parent = [i for i in range(n+1)]
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            parent[(j+1)] = find_parent(i+1)
travel_list = list(set(list(map(int,input().split()))))
flag = True
for i in range(len(travel_list)-1):
    if parent[travel_list[i]] != parent[travel_list[i+1]]:
        flag = False
if flag:
    print("YES")
else:
    print("NO")

