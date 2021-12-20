# 분할정복
def dfs(S1,S2,i,j,level):
    answer = 0
    while i < len(S1) and j < len(S2):
        if S1[i] == S2[j] and S1[i] == 'p':
            i += 1
            j += 1
            level += 1
        else:
            if S1[i] == 'p':
                if S2[j] == 'w':
                    S2 = S2[:j] + 'pwww' + S2[j:]
                    answer += dfs(S1,S2,level+1,i+1,j)
                else:
                    answer += (1024 //(4**(level)))
                i += 5
                j += 1
            elif S2[j] == 'p':
                if S1[i] == 'w':
                    S1 = S1[:j] + 'www' + S1[j:]
                    answer += dfs(S1[i:],S2[j+1:],level+1)
                else:
                    answer += (1024 //(4**(level)))
                j += 5
                i += 1
            else:
                if S1[i] == 'b' or S2[j] == 'b':
                    answer += (1024 //(4**(level)))
                i += 1
                j += 1
    return answer

def solution(S1,S2):
    answer = dfs(S1,S2,0)    
    return answer
print(solution("ppwwwbpbbwwbw","pwbwpwwbw"))
# print(solution("b","w"))
# print(solution("b","pwbwpwwbw"))
# print(solution("w","pwbwpwwbw"))