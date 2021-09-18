def solution(N, stages):
    a = [0] * (N+1)
    q = [(0,i) for i in range(1,N+2)]
    answer = []
    size = len(stages)
    for i in stages:
        a[i-1] += 1
    print(a)
    for i,v in enumerate(a):
        if size <= 0:
            break
        failure = v / size
        size -= v
        q[i] = (failure,i+1)
    print(q)
    q = q[:-1]
    print(q)
    ab = sorted(q, key=lambda x:(-x[0],x[1]))
    print(ab)
    for i in range(len(ab)):
        answer.append(ab[i][1])
    
    return answer
print(solution(5, [2, 1, 2, 3, 2, 4, 3, 3]))