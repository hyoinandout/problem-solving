n = int(input())

arr = [0] * (1001)
arr[1] = 0
arr[2] = 1
for i in range(3,n+1):
    if i % 2 != 0:
        arr[i] = arr[i-1] * 2 - 1
    else:
        arr[i] = arr[i-1] * 2 + 1

print(arr[n])