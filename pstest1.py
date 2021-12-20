def dfs(n,capacity,files,visited,cnt,cap):
    if n <= 0:
        return cnt-1
    result = 0 
    for i in range(len(files)):
        if visited[i] == False:
            if files[i] <= capacity:
                visited[i] = True
                result = max(result,dfs(n,capacity-files[i],files,visited,cnt+1,cap))
                visited[i] = False
            else:
                visited[i] = True
                result = max(result,dfs(n-1,cap-files[i],files,visited,cnt+1,cap))
                visited[i] = False
    return result

def solution(n,capacity,files):
    files.sort()
    visited = [False] * len(files)
    answer = dfs(n,capacity,files,visited,0,capacity)
    return answer

print(solution(2,5,[1,2,3,4,5]))
print(solution(1,5,[1,4,5]))
print(solution(2,3,[2,2,2,2,2]))