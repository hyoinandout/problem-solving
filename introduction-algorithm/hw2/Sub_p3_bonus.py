def budget(evaluation):
    up = 1
    down = 0
    level = 1
    peak = 0
    for i in range(1,len(evaluation)):
        if evaluation[i]>evaluation[i-1]:
            up += 1
            down =  0
            level += up
            peak = up
        elif evaluation[i]==evaluation[i-1]:
            down = 0
            peak = 0
            up = 1
            level += 1
        else:
            down+=1
            up = 1
            level += down
            if peak <= down:
                level += 1                
    return level * 1000
print(budget([1,0,2]))
print(budget([1,2,1,2,1]))
print(budget([12,4,3,11,34,34,1,67]))
print(budget([1,2,3,4,6,4,3,1,2,7,6,4,3,3,2,1,1,2,2,2,4,3] ))