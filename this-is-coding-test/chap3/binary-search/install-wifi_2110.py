# 이진탐색 왼쪽 오른쪽 판별 조건 + 답 안보일 땐 말 그대로 구현해보기

# def BS(s,e,arr,ans):
#     if s > e:
#         return
#     mid = (s+e)//2
#     if (arr[0] + mid) in arr or (arr[-1] - mid) in arr:
#         ans.append(mid)
#         return
#     BS(s,mid-1,arr,ans)
#     BS(mid+1,e,arr,ans)


n,c = map(int,input().split())
arr = []
#ans = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()

low = 1
high = arr[-1]-arr[0]
answer = -1

while low <= high:
    mid = (low + high)//2
    cnt = 0
    i = 0
    for j in range(n):
        if arr[i] + mid <= arr[j]:
            cnt += 1
            i = j
    if cnt >= (c-1):
        low = mid + 1
        if answer < mid:
            answer = mid
    else:
        high = mid - 1
    

print(answer)

            


#BS(1,(arr[n-1]-arr[0])//(c-1),arr,ans)
#ans.sort()
#print(ans[-1])

