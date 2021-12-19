import heapq
def sorted_list(lists):
    answer = []
    heap = []
    for list in lists:
        heapq.heappush(heap,[len(list),list])
    
    def merge(a,b):
        result = []
        i=0
        j=0
        while i < len(a) and j < len(b):
            if a[i] < b[j]:
                result.append(a[i])
                i += 1
            else:
                result.append(b[j])
                j += 1
        while i < len(a):
            result.append(a[i])
            i += 1
        while j < len(b):
            result.append(b[j])
            j += 1
        return result

    while len(heap) > 1:
        firstLength, firstList = heapq.heappop(heap)
        secondLength, secondList = heapq.heappop(heap)
        answer = merge(firstList,secondList)
        heapq.heappush(heap,[len(answer),answer])
    if heap: 
        answerLength, answer = heapq.heappop(heap)
    else:
        answer = []
    return answer
#print(sorted_list([[1,4,5],[1,3,4],[2,6]]))
        

    