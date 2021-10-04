def mergeSort(nums):
    if len(nums) > 1:
        mid = len(nums) // 2
        L = nums[:mid]
        R = nums[mid:]
        mergeSort(L)
        mergeSort(R)
        i,j,k=0,0,0
        while i<len(L) and j<len(R):
            if L[i] < R[j]:
                nums[k] = L[i]
                i += 1
            else:
                nums[k] = R[j]
                j += 1
            k+=1
        while i<len(L):
            nums[k] = L[i]
            i += 1
        while j<len(R):
            nums[k] = R[j]
            j += 1            
    return nums

def findTarget(numArr, target):
    for i,v in enumerate(numArr):
        if target <= v:
            return i
    return len(numArr)

def solve(nums, target):
    return (findTarget(mergeSort(nums),target) + 1)
    

print(solve([13,59,30,40,10],59))
print(solve([1,3,5,6],0))
print(solve([1,3,5,6,2],4))
print(solve([5,4,-2,-6,9],10))