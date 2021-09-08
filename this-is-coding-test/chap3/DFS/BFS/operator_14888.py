n = input()
a = list(map(int,input().split()))
o = list(map(int,input().split()))
k = []

def cal(a,k):
    n = a[0]
    for i in range(len(k)):
        if k[i] == 0:
            n += a[i+1]
        elif k[i] == 1:
            n -= a[i+1]
        elif k[i] == 2:
            n *= a[i+1]
        else:
            if n<0:
                n = -((-n) // a[i+1])
            else:
                n = n // a[i+1]
        #print(n)
    
    return n


def dfs(a,o,k,result):
    if sum(o)==0:
        #print(k)
        result.append(cal(a,k))
        return
    for i in range(4):
        if o[i] == 0:
            continue
        k.append(i)
        o[i] -= 1
        dfs(a,o,k,result)
        k.pop()
        o[i] += 1
result = []
dfs(a,o,k,result)
print(max(result))
print(min(result))
