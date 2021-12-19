from collections import deque
def LanguageOrder(words):
    graph = [[] for _ in range(26)]
    indegree = [0] * 26 
    occurence = set()
    for i in range(len(words)-1):
        flag = True
        for j in range(len(words[i])):
            occurence.add(words[i][j])
            if flag:
                if words[i][j] != words[i+1][j]:
                    graph[ord(words[i][j])-97].append(ord(words[i+1][j])-97)
                    indegree[ord(words[i+1][j])-97] += 1
                    flag = False
    for i in range(len(words[len(words)-1])):
        occurence.add(words[len(words)-1][i])
    # print(graph)
    # print(indegree)
    # print(occurence)
    q = deque()
    for i in range(26):
        if indegree[i] == 0:
            if chr(i+97) in occurence:
                q.append(i)
    answer = ""
    while q:
        now = q.popleft()
        answer += chr(now+97)
        for incident in graph[now]:
            indegree[incident] -= 1
            if indegree[incident] == 0:
                q.append(incident)
    return answer
# print(LanguageOrder( ["xwt","xwf","aw","att","wftt"] ))
# print(LanguageOrder( ["a","l"] ))
# print(LanguageOrder( ["a","l","a"] ))


