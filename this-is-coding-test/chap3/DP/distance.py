#틀림
a = input()
b = input()
# dist = 0
# cnt = abs(len(b) - len(a))
# dist += cnt
n = len(a)
m = len(b)

dp = [[0] * (m+1) for _ in range(n+1)]
for i in range(n+1):
    dp[i][0] = i
for i in range(m+1):
    dp[0][i] = i

for i in range(1,n+1):
    for j in range(1,m+1):
        if a[i] != b[j]:
            dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
        else:
            dp[i][j] = dp[i-1][j-1]
print(dp[n][m])


