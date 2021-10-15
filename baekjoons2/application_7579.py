n,m = map(int,input().split())
mem = [0]
cost = [0]
mem += list(map(int,input().split()))
cost += list(map(int,input().split()))

# 메모리의 총합이 메모리 초과가 나기 때문에, 메모리의 총합이 아닌 코스트의 총합으로 풀어보자.
# dp = [[10000001] * (m+1) for _ in range(n+1)]
# for i in range(1,n+1):
#     for j in range(1,m+1):
#         if mem[i] >= j:
#             dp[i][j] = min(dp[i-1][j],cost[i])
#         else:
#             dp[i][j] = min(dp[i-1][j-mem[i]]+cost[i],dp[i-1][j])

# print(dp[n][m])

dp = [[0] * 10001 for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1, 10001):
        if j >= cost[i]:
            dp[i][j] = max(dp[i-1][j-cost[i]]+mem[i],dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

for index,case in enumerate(dp[n]):
    if case >= m:
        print(index)
        break


