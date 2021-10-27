def partition(arr,l,h):
    pivot = arr[l]
    i,j = l,h
    if j-i == 1: 
        if arr[i] > arr[j]:
            arr[j], arr[i] = arr[i], arr[j]
        j = l
    else:
        while i < j:
            i += 1
            while(pivot >= arr[i]):
                i += 1
            j -= 1
            while(pivot < arr[j]):
                j -= 1
            if i < j:
                arr[i], arr[j] = arr[j], arr[i]
        arr[l], arr[j] = arr[j], arr[l]
    return j

def quickSort(arr,l,h):
    if l < h:
        j = partition(arr,l,h)
        quickSort(arr,l,j)
        quickSort(arr,j+1,h)

#a = [5,2,4,7,1,3,2,6]
a=[7,6]

quickSort(a,0,len(a)-1)
print(a)