def bs(s,e,arr):
    if s > e:
        return -1
    mid = (s + e) // 2
    if arr[mid] == mid:
        return mid
    elif arr[mid] > mid:
        return bs(s,mid-1,arr)
    else:
        return bs(mid+1,e,arr)


n = int(input())
arr = list(map(int,input().split()))

print(bs(0,n-1,arr))
