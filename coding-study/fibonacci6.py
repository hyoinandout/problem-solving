import copy
# 수학
# def fibonacci(n):
#     if n <= 1:
#         return n
    
#     if n % 2 == 0:
#         a = fibonacci(n // 2)
#         b = fibonacci((n // 2) + 1)
#         return a*a + b*b
#     else:
#         result = 0
#         while (n < 3):
#             result += fibonacci((n-1))
#             n-= 2
#         return result

# print(fibonacci(17))

arr = [[1,1],[1,0]]
def fibonacci(n):
    if n <= 1:
        return arr
    if n % 2 == 0:
        a = copy.deepcopy(fibonacci((n//2)))
        b = copy.deepcopy(a)
    else:
        a = copy.deepcopy(fibonacci(n-1))
        b = copy.deepcopy(arr)
    result = [[0] * 2 for _ in range(2)]
    for i in range(2):
        for j in range(2):
            partResult = 0
            for k in range(2):
                partResult += (a[i][k] * b[k][j])%1000000007
            result[i][j] = partResult%1000000007
    return result
    
n = int(input())
resultArr = fibonacci(n)
print(resultArr[0][1]%1000000007)