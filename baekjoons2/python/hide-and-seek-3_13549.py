from collections import deque
n,k = map(int,input().split())

def f(n,k):
    dp = [0] * 200001
    visited = [False] * 200001
    q = deque()
    dp[n] = 0
    visited[n] = True
    q.append(n)
    n *= 2

    while n <= 2*k:
        dp[n] = 0
        visited[n] = True
        q.append(n)
        n *= 2
        if n == 0:
            break

    time = 0
    while q:
        size = len(q)
        for i in range(size):
            start = q.popleft()
            visited[start] = True
            if start == k:
                return time
            left = start - 1
            right = start + 1
            if left >= 0 and visited[left] == False:
                q.append(left)
                visited[left] = True
                left *= 2
                while left <= 2*k:
                    if visited[left]:
                        break
                    visited[left] = True
                    q.append(left)
                    left *= 2


            if right <= 2*k and visited[right] == False:
                visited[right] = True
                q.append(right)
                right *= 2
                while right <= 2*k:
                    if visited[right]:
                        break
                    visited[right] = True
                    q.append(right)
                    right *= 2
        time += 1   
print(f(n,k))