n = int(input())
dp = [0] * 21
arr = [[0] for _ in range(21)]
for i in range(1,n+1):
    t,p = map(int,input().split())
    arr[i+t-1].append(dp[i-1]+p)
    dp[i] = max(max(arr[i]),dp[i-1])
#print(arr)
#print(dp)
print(dp[n])