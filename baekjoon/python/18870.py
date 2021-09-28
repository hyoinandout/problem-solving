import heapq

n = int(input())
arr = list(map(int,input().split()))
flag = set(arr)
sort_arr = []
for i in flag:
    heapq.heappush(sort_arr,i)
s = {}
cnt = 0
size = len(sort_arr)
for _ in range(size):
    s[heapq.heappop(sort_arr)] = cnt
    cnt += 1
answer = []
for i in arr:
    answer.append(s[i])
print(''.join(str(answer)[1:-1].split(',')))