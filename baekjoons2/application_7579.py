n,m = map(int,input().split())
mem = [0]
cost = [0]
mem += list(map(int,input().split()))
cost += list(map(int,input().split()))

dp = [[87654321] * (m+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        if mem[i] > j:
            dp[i][j] = min(dp[i-1][j],cost[i])
        else:
            dp[i][j] = min(dp[i-1][j-mem[i]]+cost[i],dp[i-1][j])

print(dp)
print(dp[n][m-1])

