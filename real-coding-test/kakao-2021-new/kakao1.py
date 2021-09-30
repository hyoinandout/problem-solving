def solution(id_list, report, k):
    d1 = [set() for _ in range(len(id_list))]
    d2 = {}
    for i in range(len(report)):
        a,b = report[i].split()
        if b in d1[id_list.index(a)]:
            continue
        else:
            d1[id_list.index(a)].add(b)
        if b in d2: 
            d2[b] += 1
        else:
            d2[b] = 1
    answer = []
    for i in range(len(id_list)):
        cnt = 0
        for j in d1[i]:
            if d2[j] >= k:
                cnt+=1
        answer.append(cnt)
    return answer