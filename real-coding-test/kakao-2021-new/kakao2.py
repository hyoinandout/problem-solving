#틀림
import math
import re
def solution(n, k):
    s = ''
    while n>0:
        n,mod = divmod(n,k)
        s += str(mod)
    s = s[::-1]
    print(s)

    b = list(map(int,(re.split(r'0+',s))))
    print(b)
    n = max(b)
    answer = 0
    array = [True] * (n+1) 
    for i in range(2, int(math.sqrt(n)) + 1): 
        if array[i] == True:
            j = 2
            while i * j <= n:
                array[i * j] = False
                j += 1    
    array[0] = False
    array[1] = False
    for i in b:
        if array[i] == True:
            answer+=1
    print(answer)
    return answer

solution(110001,10)