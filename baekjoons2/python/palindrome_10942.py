import sys



n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))

dp = [[0] * (n+1) for _ in range(n+1)]

for i in range(1,n+1):
    dp[i][i] = 1

for i in range(1,n):
    j = i + 1
    if arr[i-1] == arr[j-1]:
        dp[i][j] = 1

for s in range(2,n):
    for i in range(1,n-s+1):
        j = i + s
        if arr[i-1] == arr[j-1]:
            dp[i][j] = dp[i+1][j-1]
        else:
            dp[i][j] = 0

m = int(sys.stdin.readline())
for _ in range(m):
    s,e = map(int,sys.stdin.readline().split())
    print(dp[s][e])
