n,m = map(int,input().split())
dp = [[987654321] * (n+1) for _ in range(n+1)]

#추가해야할 부분 : 공통된 형식
for i in range(1,n+1):
    dp[i][i] = 0


for _ in range(m):
    a,b = map(int,input().split())
    dp[a][b] = 1

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j])

for i in range(1,n+1):
    for j in range(1,n+1):
        if dp[i][j] == 987654321:
            dp[i][j] = 0
        print(dp[i][j],end=' ')
    print()


result = 0
for s in range(1,n+1):
    cnt = 0
    for k in range(1,n+1):
        x = dp[s][k] + dp[k][s]
        if x == 0:
            if k == s:
                pass
            else:
                break
        cnt += 1
    if cnt == n:
        result += 1
print(result)
        