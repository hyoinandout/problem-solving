def maxScore(nums):
    nums = [1] + nums + [1]
    dp = [[0] * len(nums) for _ in range(len(nums))]
    for s in range(1,len(nums)-1):
        for i in range(0,len(nums)-s-1):
            j = i+s
            maxResult = 0
            for k in range(i,j):
                candid = dp[i][k] + dp[k+1][j] + nums[i] * nums[k+1] * nums[j+1]
                if candid > maxResult:
                    maxResult = candid
            dp[i][j] = maxResult
    return dp[0][len(nums)-2]
    

print(maxScore([1,3]))
print(maxScore([5,6,7]))
print(maxScore([3,1,5,8]))
print(maxScore([1,3,5,6,2]))
