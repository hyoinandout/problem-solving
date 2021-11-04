def array_multiply(num, array):
    if num == 1:
        return array
    x = array_multiply(num//2, array)
    y = array_multiply(num-(num//2), array)

    for i in range(len(y)):
        for j in range(len(y)):
            partialResult = 0
            for k in range(len(y)):
                partialResult += (x[i][k] * y[k][j])
            array[i][j] = partialResult % 1000
    return array

n,b = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))

result = array_multiply(2,arr)

for i in range(n):
    for j in range(n):
        print(result[i][j], end= ' ')
    print()


