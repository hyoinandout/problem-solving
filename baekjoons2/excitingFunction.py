def excitingFunction(a,b,c,arr):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    if a > 20 or b > 20 or c > 20:
        return excitingFunction(20,20,20,arr)
    if arr[a][b][c] != 0:
        return arr[a][b][c]
    if a < b and b < c:
        arr[a][b][c] = excitingFunction(a,b,c-1,arr) + excitingFunction(a,b-1,c-1,arr) - excitingFunction(a,b-1,c,arr)
        return arr[a][b][c]
    else:
        arr[a][b][c] = excitingFunction(a-1,b,c,arr) + excitingFunction(a-1,b-1,c,arr) + excitingFunction(a-1,b,c-1,arr) - excitingFunction(a-1,b-1,c-1,arr)
        return arr[a][b][c]

arr = [[[0] * 50 for _ in range(50)] for _ in range(50)]
while True:
    a,b,c = map(int,input().split())
    if a == -1 and b == -1 and c == -1:
        break
    print(f'w({a}, {b}, {c}) =', excitingFunction(a,b,c,arr))