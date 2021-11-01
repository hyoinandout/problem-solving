# 항상 거리의 합인거 생각해서 초기화!
n = int(input())
dp = [[987654321] * (n+1) for _ in range(n+1)]
m = int(input())
for _ in range(m):
    i,j,cost = map(int,input().split())
    dp[i][j] = min(dp[i][j],cost)
for i in range(1,n+1):
    dp[i][i] = 0
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
