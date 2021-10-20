# 탑다운, 바텀업으로 다시한번 풀어보자.
n = int(input())
arr = [0,0,0]
#arr = [ int(input()) for _ in range(n) ]
for _ in range(n):
    arr.append(int(input()))
for _ in range(3):
    arr.append(0)
dp = [0] * (n + 6)

#for i in range(4,n+8):

    #이렇게 하면 OOXO가 고려되지 않는다.
    #dp[i] = dp[i-4] + max(arr[i]+arr[i-1],arr[i]+arr[i-2],arr[i-1]+arr[i-2])
for i in range(3,n+6):
    #띄어쓰기를 어디에 둘것인가?
    dp[i] = max(dp[i-1],arr[i] + dp[i-2],arr[i]+arr[i-1]+dp[i-3])
#print(dp)
print(max(dp))
