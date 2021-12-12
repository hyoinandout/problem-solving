# Height 말고 width 중심 접근 풀이
# 시간복잡도에 해당하기만 한다면 안전하게 다 탐색해주는 것이 좋긴 하다.

# def solution(height):
#     indexedHeight = []
#     answer = 0
#     for idx,val in enumerate(height):
#         indexedHeight.append([val,idx])
#     indexedHeight.sort()
#     for i in range(len(indexedHeight)-1):
#         criteriaindex = indexedHeight[i][1]
#         startindex = min(indexedHeight[i][1],indexedHeight[i+1][1])
#         endindex = max(indexedHeight[i][1],indexedHeight[i+1][1])
#         for j in range(i+1,len(indexedHeight)):
#             if startindex < indexedHeight[j][1] < endindex:
#                 continue
#             else:
#                 if indexedHeight[j][1] < startindex:
#                     startindex = indexedHeight[j][1]
#                 elif indexedHeight[j][1] > endindex:
#                     endindex = indexedHeight[j][1]
#             answer = max(answer,min(indexedHeight[i][0],indexedHeight[j][0]) * abs(indexedHeight[i][1] - indexedHeight[j][1]))
#         return answer
def solution(height):
    maxWidth = len(height)-1
    left = 0
    right = maxWidth
    container = 0
    containerHeight = 0
    while maxWidth > 0:
        flag = True
        if height[left] < height[right]:
            containerHeight = height[left]
        else:
            containerHeight = height[right]
            flag = False
        container = max(container,containerHeight * maxWidth)
        if flag:
            left += 1
        else:
            right -= 1
        maxWidth -= 1
    return container
# print(solution([1,8,6,2,5,4,8,3,7]))
# print(solution([1,1]))
# print(solution([4,3,2,1,4]))
# print(solution([1,2,1]))
print(solution([1,3,2,5,25,24,5]))

        
        
        
        
