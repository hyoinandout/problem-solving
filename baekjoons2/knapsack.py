
# def dpFunc(arr,i,weightLimit):
#     if i >= len(arr):
#         return 0
#     if weightLimit >= arr[i][0]:
#         return max(dpFunc(arr,i+1,weightLimit-arr[i][0])+arr[i][1],dpFunc(arr,i+1,weightLimit))
#     else:
#         return 0



n,k = map(int,input().split())
arr = []
for _ in range(n):
    w,v = map(int,input().split())
    arr.append([w,v])

arr.sort()
#print(arr)
#dp = [0] * (200001)
# dp = [[0] * (k+1) for _ in range(n+1)]


# for i in range(k+1):
#     for j in range(n):
#         if dp[i+arr[j][0]] < dp[i]+arr[j][1]:

# tabulation

# for i in range(1,n+1):
#     for j in range(1,k+1):
#         if j>=arr[i][0]:
#             dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i][0]]+arr[i][1])
#         else:
#             dp[i][j] = dp[i-1][j]

# memoization -> X

# 시간 초과
#print(dpFunc(arr,0,k))

# memoization2
dp2 = [0] * (k+1)
for w,v in arr:
    for j in range(k,w-1,-1):
        dp2[j] = max(dp2[j],dp2[j-w]+v)

print(dp2[k])
#print(dp)
#print(dp[n][k])
