#문제 아이디어는 완전 탐색으로 각 노드 방문할 때 마다 return 할 수 있다고 하고 계속 시작 노드에서 dfs 하는거 
def solution(info, edges):
    adj = [] * len(info)
    for i in edges:
        adj[i[0]].append(i[1])
    
    def dfs(info, adj, start, x, y):
        if x <= y:
            return 0
        maxSheep = 0
        for i in adj[info[start]]:
            if info[i] == 0:
                maxSheep += dfs(info,adj,i,x+1,y)
            else:
                maxSheep += dfs(info,adj,i,x,y+1)
        return maxSheep

    print(dfs(info,adj,0,0,0))
    answer = 0
    return answer
solution([0,0,1,1,1,0,1,0,1,0,1,1],[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]])