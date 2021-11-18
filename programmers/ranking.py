# 플로이드 와샬 경유점 항상 명시하기 !!
def solution(n, results):
    dp = [[987654321] * (n+1) for _ in range(n+1)]
    for i in range(1,n+1):
        dp[i][i] = 0
    for result in results:
        dp[result[0]][result[1]] = 1
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j])
    answer = 0
    for i in range(1,n+1):
        cnt = 0
        for j in range(1,n+1):
            if dp[i][j] != 987654321 or dp[j][i] != 987654321:
                if dp[i][j] != 987654321 and dp[j][i] != 987654321:
                    if i == j:
                        pass
                    else:
                        continue
                cnt += 1
        if cnt == n:
            #print(i)
            answer += 1
    return answer
print(solution(5,[[1,4],[4,2],[2,5],[5,3]]))
print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))