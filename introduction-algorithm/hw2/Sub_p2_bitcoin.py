def max_profit(cost):
    answer = 0
    for i in range(len(cost)-1):
        if cost[i] < cost[i+1]:
            answer += cost[i+1]-cost[i]
    return answer
print(max_profit([2,4,6,20]))
print(max_profit([14,2,10,6,12,8]))