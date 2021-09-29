t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    arr = list(map(int,input().split()))
    golds = [[0] * m for _ in range(n+2)]
    for i in range(n):
        for j in range(m):
            golds[i+1][j] = arr[m*i+j]
    print(golds)
    dp = [[0] * m for i in range(n+2)]
    for i in range(n):
        dp[i+1][0] = golds[i+1][0]
    print(dp)
    for j in range(1,m):
        for i in range(1,n+1):
            dp[i][j] = max(dp[i-1][j-1],dp[i+1][j-1],dp[i][j-1]) + golds[i][j]
    result = 0
    print("dp",dp)
    for i in range(1,n+1):
        result = max(result, dp[i][m-1])
    print(result)

    
