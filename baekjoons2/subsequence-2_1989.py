# index를 한칸 씩 밀어주는 이유
import sys
from collections import deque
n = int(sys.stdin.readline().rstrip())
arr = [0] + list(map(int,sys.stdin.readline().rstrip().split()))
sum = [0] * (n+1)
for i in range(1,n+1):
    sum[i] = sum[i-1] + arr[i]

maxSeg = deque()
maxSeg.append((0,0))
maxResult = 0

def maxSubArray(start,end):
    global maxSeg
    global maxResult
    if start == end:
        return 0
    if start + 1 == end:
        ans = arr[start] ** 2
        if ans >= maxResult:
            maxResult = ans
            maxSeg.append((start,start))
        return ans
    mid = (start + end) // 2
    candid = 0
    a = maxSubArray(start,mid)
    b = maxSubArray(mid,end)
    if a > b:
        candid = a
        if a >= maxResult:
            maxResult = a
            maxSeg.append((start,mid-1))
    else:
        candid = b
        if b >= maxResult:
            maxResult = b
            maxSeg.append((mid,end-1))
    
    p,q,l,r,h = 0,0,mid,mid,arr[mid]
    while r-l <= end-start:
        if start < l:
            p = min(h,arr[l-1])
        else:
            p = -1
        if end - 1 > r:
            q = min(h,arr[r+1])
        else:
            q = -1
        if p >= q:
            h = p
            l -= 1
        else:
            h = q
            r += 1
        if maxResult <= ((sum[r] - sum[l-1]) * h):
            maxResult = (sum[r] - sum[l-1]) * h
            maxSeg.append((l,r))
        if candid < ((sum[r] - sum[l-1]) * h):
            candid = (sum[r] - sum[l-1]) * h
    return candid

result = maxSubArray(1,n+1)
if sum[n] * min(arr) >= maxResult:
    maxSeg.append((1,n))
print(maxResult)
k = maxSeg.pop()
print(k[0],k[1])