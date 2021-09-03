# 문제 속에 답이 있다.
from collections import deque

n,m,k,x = map(int,input().split())
e = [[] * n for _ in range(n)] 
v = [False] * n
for _ in range(m):
    d,a = map(int,input().split())
    e[d-1].append(a-1)
q = deque()
q.append(x-1)
v[x-1] = True
cnt = 0
answer = []
while q and cnt <= k:
    for _ in range(len(q)):
        front = q.popleft()
        if cnt == k:
           answer.append(front) 
        for i in range(len(e[front])):
            if v[e[front][i]] == False:
                v[e[front][i]] = True
                q.append(e[front][i])
    cnt+=1
if answer :
    answer.sort()
    for i in range(len(answer)):
        print(answer[i]+1)
else :
    print(-1)
