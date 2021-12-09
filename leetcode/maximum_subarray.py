class Solution: 
    def findCross(nums):
        n = len(nums)
        if len(nums) <= 1:
            return nums[0]
        mid = n // 2
        leftMax = -987654321
        rightMax = -987654321
        leftResult = 0
        rightResult = 0
        for num in nums[mid-1::-1]:
            leftResult += num
            leftMax = max(leftMax,leftResult)
        for num in nums[mid:]:
            rightResult += num
            rightMax = max(rightMax,rightResult)
        return leftMax + rightMax
        
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return nums[0]
        mid = n // 2
        a=Solution.maxSubArray(self,nums[:mid])
        b=Solution.maxSubArray(self,nums[mid:])
        c=Solution.findCross(nums)
        result = max(a,max(b,c))
        return result
                
                
                
                
                
            
        
        
        