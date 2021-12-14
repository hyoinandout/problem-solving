class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [0] * n
        localMax = nums[0]
        i = 0
        while localMax > 0 and i < n-1:
            i += 1
            dp[i] += 1
            localMax -= 1
            if nums[i] >= localMax:
                localMax = nums[i]
        if dp[n-1] > 0 or n == 1:
            return True
        else:
            return False