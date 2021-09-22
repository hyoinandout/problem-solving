def bsl(s,e,t,arr):
    mid = (s+e)//2
    if s > e:
        return s
    if arr[mid] > t+0.5:
        return bsl(s,mid-1,t,arr)
    else:
        return bsl(mid+1,e,t,arr)

def bss(s,e,t,arr):
    mid = (s+e)//2
    if s > e:
        return e
    if arr[mid] < t-0.5:
        return bss(mid+1,e,t,arr)
    else:
        return bss(s,mid-1,t,arr)

n,x = map(int,input().split())
arr = list(map(int,input().split()))
k = bsl(0,n-1,x,arr)-bss(0,n-1,x,arr)-1
if k == 0:
    print(-1)
else:
    print(k)