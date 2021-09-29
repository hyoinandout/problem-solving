n = int(input())
arr = []
dp = [[0] * n for _ in range(n)]
for _ in range(n):
    arr.append(list(map(int,input().split())))
#print(arr)
dp[0][0] = arr[0][0]
for i in range(1,n):
    for j in range(i+1):
        if i == j:
            dp[i][j] = dp[i-1][j-1] + arr[i][j]
        elif j == 0:
            dp[i][j] = dp[i-1][j] + arr[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j]
# result = 0
# for i in range(n):
#     result = max(result, dp[n-1][i])
#print(result)
print(max(dp[n-1]))

 