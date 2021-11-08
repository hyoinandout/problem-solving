# 아이디어는 맞았으나, 시간 복잡도 때문에 불가능함
# cnt = 0
# result = True
# for order in range(1,p+1):
#     entrance = int(input())
#     flag = False
#     last_num = 0
#     for candidate in range(1,entrance+1):
#         if entrance_list[candidate] == 0:
#             flag = True
#             last_num = candidate
#     if flag and result:
#         entrance_list[last_num] = order
#         cnt += 1
#     else:
#         if result:
#             print(cnt)        
#         result = False

# union-find 응용임.

g = int(input())
p = int(input())
parent = [i for i in range(g+1)]
cnt = 0

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

for _ in range(1,p+1):
    data = find_parent(parent,int(input()))
    if data == 0:
        break
    union(parent,data,data-1)
    cnt += 1

print(cnt)