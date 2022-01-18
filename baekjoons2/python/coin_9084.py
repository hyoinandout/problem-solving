t = int(input())
for _ in range(t):
    n = int(input())
    coins = list(map(int,input().split()))
    value = int(input())
    dp = [[0] * (value+1) for _ in range(n+1)]
    for j in range(0,value+1):
        if j % coins[0] == 0:
            dp[1][j] = 1
    for i in range(2,n+1):
        for j in range(0,value+1):
            if j >= coins[i-1]:
                dp[i][j] =  dp[i-1][j] + dp[i][j-coins[i-1]]
            else:
                dp[i][j] = dp[i-1][j]
    print(dp[n][value])
