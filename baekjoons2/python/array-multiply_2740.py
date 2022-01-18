def find_num(n,m,k):
    size = max(n,m,k)
    power = 0
    while size > (2**power):
        power += 1
    return (2**power)
n,m = map(int,input().split())
A = []
for _ in range(n):
    A.append(list(map(int,input().split())))
m,k = map(int,input().split())
B = []
for _ in range(m):
    B.append(list(map(int,input().split())))

size = find_num(n,m,k)
for i in range(size):
    if i < n:
        for j in range(size-m):
            A[i].append(0)
    else:
        A.append([0]*size)
for i in range(size):
    if i < m:
        for j in range(size-k):
            B[i].append(0)
    else:
        B.append([0]*size)

def add(m1,m2,k):
    arr = [[0] * k for _ in range(k)]
    for i in range(k):
        for j in range(k):
            arr[i][j] = m1[i][j] + m2[i][j]
    return arr

def sub(m1,m2,k):
    arr = [[0] * k for _ in range(k)]
    for i in range(k):
        for j in range(k):
            arr[i][j] = m1[i][j] - m2[i][j]
    return arr

def strassen(m1,m2,k):
    arr = [[0] * k for _ in range(k)]
    if k == 1:
        arr[0][0] = m1[0][0] * m2[0][0]
        return arr
    
    size = k // 2
    A11 = [[0] * size for _ in range(size)]
    A12 = [[0] * size for _ in range(size)]
    A21 = [[0] * size for _ in range(size)]
    A22 = [[0] * size for _ in range(size)]

    B11 = [[0] * size for _ in range(size)]
    B12 = [[0] * size for _ in range(size)]
    B21 = [[0] * size for _ in range(size)]
    B22 = [[0] * size for _ in range(size)]

    C11 = [[0] * size for _ in range(size)]
    C12 = [[0] * size for _ in range(size)]
    C21 = [[0] * size for _ in range(size)]
    C22 = [[0] * size for _ in range(size)]

    for i in range(size):
        for j in range(size):
            A11[i][j] = m1[i][j]
            A12[i][j] = m1[i][size+j]
            A21[i][j] = m1[size+i][j]
            A22[i][j] = m1[size+i][size+j]

            B11[i][j] = m2[i][j]
            B12[i][j] = m2[i][size+j]
            B21[i][j] = m2[size+i][j]
            B22[i][j] = m2[size+i][size+j]
    
    M1 = strassen(A11,sub(B12,B22,size),size)
    M2 = strassen(add(A11,A12,size),B22,size)
    M3 = strassen(add(A21,A22,size),B11,size)
    M4 = strassen(A22,sub(B21,B11,size),size)
    M5 = strassen(add(A11,A22,size),add(B11,B22,size),size)
    M6 = strassen(sub(A12,A22,size),add(B21,B22,size),size)
    M7 = strassen(sub(A11,A21,size),add(B11,B12,size),size)

    C11 = add(sub(add(M5,M4,size),M2,size),M6,size)
    C12 = add(M1,M2,size)
    C21 = add(M3,M4,size)
    C22 = sub(sub(add(M5,M1,size),M3,size),M7,size)

    for i in range(size):
        for j in range(size):
            arr[i][j] = C11[i][j]
            arr[i][j+size] = C12[i][j]
            arr[i+size][j] = C21[i][j]
            arr[i+size][j+size] = C22[i][j]
    
    return arr

C = strassen(A,B,size)

for i in range(n):
    for j in range(k):
        print(C[i][j],end=' ')
    print()