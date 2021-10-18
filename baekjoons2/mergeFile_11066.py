# 점화식 생각못함 -> 틀림
# 블로그 포스팅하기
import sys
t = int(sys.stdin.readline())
for _ in range(t):
    k = int(sys.stdin.readline())
    arr = list(map(int,sys.stdin.readline().split()))
    dp = [[0] * (k+1) for _ in range(k+1)]
    # for i in range(1,k+1):
    #     dp[i][i] = arr[i-1]
    for s in range(1,k):
        for i in range(1,k+1-s):
            j = i + s
            localMin = 987654321
            for x in range(i,j):
                # a = 2 * dp[i][x]
                # b = 2 * dp[x+1][j]
                # if i == x:
                #     a = dp[i][x]
                # if x+1 == j:
                #     b = dp[x+1][j]
                candid = dp[i][x] + dp[x+1][j] + sum(arr[i-1:j])
                if candid < localMin:
                    localMin = candid
            dp[i][j] = localMin
    print(dp[1][k])
                    

