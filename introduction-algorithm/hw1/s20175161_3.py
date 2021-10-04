def maxScore(nums):
    if((len(nums)<5)):
        return nums[1] * nums[2] + nums[2]
    sortedNums = sorted(nums)
    maxSet = sortedNums[-3:]
    nums.insert(0,1)
    nums.append(1)
    sum = 0
    for i in range(1,len(nums)-1):
        fig = sorted(nums[i-1],nums[i],nums[i+1]) 
        flag = True
        for j in range(3):
            if fig[j] != maxSet[j]:
                flag = False
        if not flag:
            indexes = []
            indexes.append(nums.index(maxSet[0]))
            indexes.append(nums.index(maxSet[1]))
            indexes.append(nums.index(maxSet[2]))
            indexes.sort()
            sum += maxScore(nums[indexes[0]+1:indexes[1]])
            sum += maxScore(nums[indexes[1]+1:indexes[2]])
        else:
            sum += fig[0] * fig[1] * fig[2]
            nums.remove(nums[i])
            break
    
    return sum

print(maxScore([1,3]))
print(maxScore([5,6,7]))
print(maxScore([3,1,5,8]))
print(maxScore([1,3,5,6,2]))
