import heapq

n = int(input())
arr = []
for _ in range(n):
    heapq.heappush(arr,int(input()))

answer = 0
while len(arr)>1:
    a = heapq.heappop(arr)
    b = heapq.heappop(arr)
    answer += a
    answer += b
    heapq.heappush(arr,a+b)
print(answer)






# if n==1:
#     print(arr[0])
# else:
#     sum = (n-1) * arr[0]
#     for i in range(1,len(arr)):
#         sum += (n-i) * arr[i]
#     print(sum)
