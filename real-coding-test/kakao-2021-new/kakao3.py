import math

def timeToMinutes(time):
    h,m = map(int,time.split(':'))
    return 60 * h + m

def calculate(totaltime,fees):
    if totaltime <= fees[0]:
        return fees[1]
    else:
        return fees[1] + math.ceil(((totaltime-fees[0])/fees[2])) * fees[3]


def solution(fees, records):
    d = {}
    totaltime = {}
    for i in records:
        time,num,inOut = i.split(' ')
        time = timeToMinutes(time)
        if num not in d:
            d[num] = time
        else:
            if num in totaltime:
                totaltime[num] += time - d[num]
                del d[num]
            else:
                totaltime[num] = time - d[num]
                del d[num]
    for i in d:
        time = timeToMinutes("23:59")
        if i in totaltime:
            totaltime[i] += time - d[i]
        else:
            totaltime[i] = time - d[i]
    print(totaltime)
    nums = list(totaltime.keys())
    nums.sort()
    answer = []
    for i in nums:
        answer.append(calculate(totaltime[i],fees))
    print(answer)
    return answer

solution([180, 5000, 10, 600],["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"])