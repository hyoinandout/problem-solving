#틀림
from itertools import combinations_with_replacement

def solution(n, info):
    arr = [i for i in range(0,11)]
    nCr = combinations_with_replacement(arr,n)
    result = 0
    answer = []
    for i in nCr:
        k = [0] * 11
        for j in i:
            k[j] += 1
        #print(k)
        appeach = 0
        ryan = 0
        for x in range(11):
            if info[x] >= k[x]:
                if info[x]>0:
                    appeach += 10-x
            else:
                if k[x]>0:
                    ryan += 10-x
        if appeach < ryan:
            if result < ryan:
                result = ryan
                answer = k.copy()
            elif result == ryan:
                for y in range(10,-1,-1):
                    if answer[y] < k[y]:
                        answer = k.copy()
                        break
                    elif answer[y] == k[y]:
                        continue
                    else:
                        break
    if len(answer) == 0:
        answer.append(-1)
    return answer
#print(solution(13,[0,0,0,0,0,0,0,0,0,0,5]))
print(solution(5,[2,1,1,1,0,0,0,0,0,0,0]))
print(solution(1,[1,0,0,0,0,0,0,0,0,0,0]))
print(solution(9,[0,0,1,2,0,1,1,1,1,1,1]))
print(solution(10,[0,0,0,0,0,0,0,0,3,4,3]))
