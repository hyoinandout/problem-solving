n = int(input())
a = list(map(int,input().split()))
a.sort()
# minimum = 987654321
# k = 0
# for i in a[::-1]:
#     result = 0
#     for j in a:
#         result += abs(i-j)
#     if minimum >= result:
#         minimum = result
#         k = i
# print(k)
print(a[((len(a)-1)//2)])