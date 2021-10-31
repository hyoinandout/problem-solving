# 범위 탐색 문제들 좀 풀어보자
# 완전 탐색인 것은 예상했는데 디테일에서 부족했음
# 틀림
def solution(lines):
    timeline = []
    for line in lines:
        line= line[11:-1]
        #print(line)
        hhmmss = line.split(':')
        donetime,duration = map(float,hhmmss[2].split())
        second = int(hhmmss[0])*3600 + int(hhmmss[1])*60 + donetime
        timeline.append([second-duration + 0.001,second])
        #print(second - duration,second)
    #print(timeline)
    candid = 0
    for i in range(len(timeline)):
        #print(timeline[i])
        cnt = 0
        for j in range(len(timeline)):
            if timeline[i][0] + 1 <= timeline[j][0] or timeline[i][0] > timeline[j][1]:
                continue
            cnt += 1
        if candid < cnt:
            candid = cnt
        cnt = 0
        for j in range(len(timeline)):
            #print(timeline[j])
            if timeline[i][1] + 1 <= timeline[j][0] or timeline[j][1] < timeline[i][1]:
                continue
            cnt += 1
        if candid < cnt:
            candid = cnt
    answer = candid
    return answer





print(solution([
"2016-09-15 01:00:04.001 2.0s",
"2016-09-15 01:00:07.000 2s"
]))
print(solution(["2016-09-15 01:00:04.002 2.0s",
"2016-09-15 01:00:07.000 2s"
]))
print(solution([
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
]))