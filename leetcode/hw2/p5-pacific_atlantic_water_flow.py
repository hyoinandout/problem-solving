from collections import deque
class Solution:              
        
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        dx = [-1,1,0,0]
        dy = [0,0,-1,1]
        def bfs(arr,i,j,n,m):
            pac = False
            atl = False
            visited = [[False] * m for _ in range(n)]
            q = deque()
            q.append([i,j])
            visited[i][j] = True
            while q:
                for _ in range(len(q)):
                    y,x = q.pop()
                    for k in range(4):
                        ny = y + dy[k]
                        nx = x + dx[k]
                        if ny < 0 or nx < 0:
                            pac = True
                            continue
                        elif ny >= n or nx >= m:
                            atl = True
                            continue
                        if not visited[ny][nx] and arr[ny][nx] <= arr[y][x]:
                            visited[ny][nx] = True
                            q.append([ny,nx])
            if pac and atl:
                return True
            else:
                return False
        answer = []
        n = len(heights)
        m = len(heights[0])
        for i in range(n):
            for j in range(m):
                if bfs(heights,i,j,n,m):
                    answer.append([i,j])
        return answer