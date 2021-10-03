# n = int(input())
# dp = [False] * 1000
# arr = []
# def ugly(i):
#     if i >= 1000:
#         return
#     if dp[i]:
#         return
#     dp[i] = True
#     arr.append(i)
#     ugly(2*i)
#     ugly(3*i)
#     ugly(5*i)
# ugly(1)
# arr.sort()
# print(arr[n-1])
n = int(input())
dp = [0] * n
next2, next3, next5 = 2,3,5
i2,i3,i5 = 0,0,0
for l in range(1,n):
    dp[l] = min(next2,next3,next5)
    if dp[l] == next2:
        i2+=1
        next2 = dp[i2] * 2
    if dp[l] == next3:
        i3+=1
        next3 = dp[i3] * 3
    if dp[l] == next5:
        i5+=1
        next5 = dp[i5] * 5
print(dp[n-1])
