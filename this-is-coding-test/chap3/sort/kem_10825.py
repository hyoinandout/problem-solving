n = int(input())
a = []
for _ in range(n):
    name,k,e,m = input().split()
    a.append((-int(k),int(e),-int(m),name))
a.sort()
for i in range(len(a)):
    print(a[i][3])
    