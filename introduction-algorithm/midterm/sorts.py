#selection sort
# def selection(array):
#     for i in range(len(array)):
#         pivot = i
#         for j in range(i,len(array)):
#             if array[pivot] > array[j]:
#                 pivot = j
#         array[pivot], array[i] = array[i], array[pivot]

#insertion sort
# def insertion(array):
#     for i in range(1,len(array)):
#         pivot = array[i]
#         j = i - 1
#         while j >= 0 and pivot <= array[j]:
#             array[j+1] = array[j]
#             j -= 1
#         array[j+1] = pivot

#merge sort
# def merge(array):
#     if len(array) == 1:
#         return array
#     mid = len(array) // 2
#     L = merge(array[:mid])
#     R = merge(array[mid:])
#     i,j,k = 0,0,0
#     while i < len(L) and j < len(R):
#         if L[i] <= R[j]:
#             array[k] = L[i]
#             i += 1
#         else:
#             array[k] = R[j]
#             j += 1
#         k += 1
    
#     while i < len(L):
#         array[k] = L[i]
#         k += 1
#         i += 1
    
#     while j < len(R):
#         array[k] = R[j]
#         k += 1
#         j += 1
    
#     return array

#quick sort
#improved version
#low high 없이 안되는 이유: i와 j의 index가 상대적으로 계속 바뀌기 때문. 따라서 절대적 index의 존재가 필요하다.
def partition(array,low,high):
    pi = array[high]
    i = low-1
    for j in range(low,high):
        if pi >= array[j]:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i+1], array[high] = array[high], array[i+1]
    return (i+1)

def quick(array,low,high):
    if len(array) == 1:
        return array
    if low < high:
        pi = partition(array,low,high)
        quick(array,low,pi-1)
        quick(array,pi+1,high)
a=[4,2,3,1,5,6,7,2]
quick(a,0,len(a)-1)
print(a)