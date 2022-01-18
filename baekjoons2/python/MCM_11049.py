n = int(input())
arr = []
dp = [[0] * n for _ in range(n)]
for _ in range(n):
    r,c = map(int,input().split())
    arr.append([r,c])

# update 문제
for s in range(1,n):
    for i in range(n-s):
        j = i + s
        candid = 987654321
        for k in range(i,j):
            localMin = dp[i][k] + dp[k+1][j]  + arr[i][0] * arr[k][1] * arr[j][1]
            if localMin < candid:
                candid = localMin
        dp[i][j] = candid

print(dp[0][n-1])
