#2
def dfs(grid,visited,direction,i,j,cnt,answer):
    if i < 0:
        i = len(grid)-1
    if j < 0:
        j = len(grid[0])-1
    if i == len(grid):
        i = 0
    if j == len(grid[0]):
        j = 0
    if visited[i][j][direction] == True:
        answer.append(cnt)
        return
    cnt+=1
    if direction == 0:
        # visited[i][j][0][0] = True
        visited[i][j][0] = True
        if grid[i][j] == 'S':
            dfs(grid,visited,0,i,j+1,cnt,answer)
        elif grid[i][j] == 'L':
            dfs(grid,visited,3,i-1,j,cnt,answer)
        elif grid[i][j] == 'R':
            dfs(grid,visited,1,i+1,j,cnt,answer)
            
    if direction == 1:
        # visited[i][j][1][0] = True
        visited[i][j][1] = True
        if grid[i][j] == 'S':
            dfs(grid,visited,1,i+1,j,cnt,answer)
        elif grid[i][j] == 'L':
            dfs(grid,visited,0,i,j+1,cnt,answer)
        elif grid[i][j] == 'R':
            dfs(grid,visited,2,i,j-1,cnt,answer)
    
    if direction == 2:
        # visited[i][j][2][0] = True
        visited[i][j][2] = True
        if grid[i][j] == 'S':
            dfs(grid,visited,2,i,j-1,cnt,answer)
        elif grid[i][j] == 'L':
            dfs(grid,visited,1,i+1,j,cnt,answer)
        elif grid[i][j] == 'R':
            dfs(grid,visited,3,i-1,j,cnt,answer)
            
    if direction == 3:
        # visited[i][j][3][0] = True
        visited[i][j][3] = True
        if grid[i][j] == 'S':
            dfs(grid,visited,3,i-1,j,cnt,answer)
        elif grid[i][j] == 'L':
            dfs(grid,visited,2,i,j-1,cnt,answer)
        elif grid[i][j] == 'R':
            dfs(grid,visited,0,i,j+1,cnt,answer)        

def check(grid,n,m,visited,answer):
    for i in range(n):
        for j in range(m):
            for k in range(4):
                if visited[i][j][k] == False:
                    cnt = 0
                    dfs(grid,visited,k,i,j,cnt,answer)

def solution(grid):
    n = len(grid)
    m = len(grid[0])
    # n = len(grid[0])*len(grid)
    # visited = [[[False for i in range(2)] for j in range(4)] for k in range(n)]
    visited = [[[False for i in range(4)] for j in range(m)] for k in range(n)]
    answer = []
    check(grid,n,m,visited,answer)
    answer.sort()
    return answer

print(solution(["S"]))