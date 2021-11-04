import copy

def array_multiply(num):
    if num == 1:
        return arr
    if num % 2 == 0:
        arr1 = copy.deepcopy(array_multiply(num//2))
        arr2 = copy.deepcopy(arr1)
    else:
        arr1 = copy.deepcopy(array_multiply(num-1))
        arr2 = copy.deepcopy(arr)
    
    arrResult = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            partialResult = 0
            for k in range(n):
                partialResult += (arr1[i][k] * arr2[k][j])
            arrResult[i][j] = partialResult % 1000    
    return arrResult

n,b = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))

result = array_multiply(b)

for i in range(n):
    for j in range(n):
        print(result[i][j], end= ' ')
    print()

