n = int(input())
dp = [False] * 1000
arr = []
def ugly(i):
    if i >= 1000:
        return
    if dp[i]:
        return
    dp[i] = True
    arr.append(i)
    ugly(2*i)
    ugly(3*i)
    ugly(5*i)
ugly(1)
arr.sort()
print(arr[n-1])

