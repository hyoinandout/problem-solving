#틀림
a = input()
b = input()
# dist = 0
# cnt = abs(len(b) - len(a))
# dist += cnt

dp = [[0] * len(b) for _ in range(len(a))]
for i in range(len(a)):
    dp[i][0] = i
for i in range(len(b)):
    dp[0][i] = i

for i in range(1,len(a)):
    for j in range(1,len(b)):
        if a[i] != b[j]:
            dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
        else:
            dp[i][j] = dp[i-1][j-1]
print(dp[len(a)-1][len(b)-1])


