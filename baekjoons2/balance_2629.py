#안전하게
#반례보고 앎
#반례 생각 방법: 어디까지 될 수 있는지 생각해보기 (선택은 주어진 입력까지, output은 쭉 한쪽에 더해가다 하나씩 옆으로 옮기면 max(marbles)를 넘어섰음에도 측정이 가능해지기 시작하므로 max(marbles)에서 멈추지 말았어야함.)
n = int(input())
weight = list(map(int,input().split()))
k = int(input())
marbles = list(map(int,input().split()))



dp = [[False] * (40001) for _ in range(n+1)]

for i in range(1,n+1):
    if weight[i-1] <= 40001:
        dp[i][weight[i-1]] = True
    for j in range(1,40001):
        if dp[i-1][j] == True:
            dp[i][j] = True
            if j+weight[i-1] <= 40001:
                dp[i][j+weight[i-1]] = True
            if j-weight[i-1] < 0:
                dp[i][weight[i-1]-j] = True
            else:
                dp[i][j-weight[i-1]] = True

answer = []
for marble in marbles:
    if dp[n][marble] is True:
        answer.append('Y')
    else:
        answer.append('N')

print(' '.join(answer))       
            