n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

#selection sort
for i in range(n):
    pivot = i
    for j in range(i+1,n):
        if arr[pivot] > arr[j]:
            pivot = j
    arr[i], arr[pivot] = arr[pivot], arr[i]
           
#insertion sort
for i in range(1,n):
    pivot = arr[i]
    j = i-1
    while j >= 0 and arr[j] > pivot:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = pivot

for i in range(n):
    print(arr[i])