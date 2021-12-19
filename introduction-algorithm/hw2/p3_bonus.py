# 거꾸로도 한번 봐보자!
class Solution:    
    def candy(self, ratings: List[int]) -> int:
        level = [1] * len(ratings)
        for i in range(len(ratings)-1):
            if ratings[i] < ratings[i+1]:
                level[i+1] = level[i] + 1
        for i in range(len(ratings)-1,0,-1):
            if ratings[i-1] > ratings[i]:
                level[i-1] = max(level[i-1],level[i]+1)
        return sum(level)