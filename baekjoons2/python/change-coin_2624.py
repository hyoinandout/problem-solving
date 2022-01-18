t = int(input())
n = int(input())
coins = [[0,0]]
for _ in range(n):
     a,b = map(int,input().split())
     coins.append([a,b])
coins.sort()
#print(coins)
dp = [[0] * (t+1) for _ in range(n+1)]

for i in range(1,n+1):
    have = 0
    for j in range(1,t+1):
        if j >= coins[i][0]:
            if j % coins[i][0] == 0 and have < coins[i][1]:
                dp[i][j] += 1
                have += 1
            for k in range(have+1):
                if j >= k * coins[i][0]:
                    dp[i][j] += dp[i-1][j- (k * coins[i][0])]
        else:
            dp[i][j] = dp[i-1][j]
print(dp[n][t])
# for i in range(1,n+1):
#     for j in range(1,t+1):
#         print(dp[i][j],end=' ')
#     print()