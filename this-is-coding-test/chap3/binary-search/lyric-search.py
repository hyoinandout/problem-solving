# 틀렸던 부분
# logic 전환하는 과정에서 손코딩 안하고 바로 즉석으로 하다보니 세심한 부분에서 놓쳤음 (???ab 같은 경우, 다 뒤집어서 bs 진행할거면 query도 뒤집어 줬어야 하는데 놓침)
# 런타임 에러 잡는 과정 : always index. 결국 반례 하나 보고 찾아서 고치긴 했는데, 막힐 경우 문제 다시 세세히 보고 특수한 경우에 대해서 test code 돌려본 다음에 런타임 잡아볼 것. 그리고 순차적으로 탐색할때 탈출조건 생각하자!!

def bsl(s,e,query,arr):
    if s>e:
        return s
    mid = (s+e)//2
    if arr[mid] > query:
        return bsl(s,mid-1,query,arr)
    elif arr[mid] == query:
        return mid
    else:
        return bsl(mid+1,e,query,arr)

arr = [[] for _ in range(10001)]
reverse_arr = [[] for _ in range(10001)]

def solution(words, queries):
    answer = []
    for word in words:
        arr[len(word)].append(word)
        reverse_arr[len(word)].append(word[::-1])
    #words = list(set(words))
    for i in range(10001):
        arr[i].sort()
        reverse_arr[i].sort()

    # n = len(words)

    # # sort
    # head = sorted(words)
    # tail = []
    # for i in words:
    #     tail.append(i[::-1])
    # tail.sort()

    # binary search
    for i in queries:
        length = len(i)
        if i[0] == "?":
            query = i[::-1].rstrip('?')
            k = bsl(0,len(reverse_arr[len(i)])-1,query,reverse_arr[len(i)])
            query2 = i[::-1].replace('?','z')
            #print(query2)
            g = bsl(0,len(reverse_arr[len(i)])-1,query2,reverse_arr[len(i)])
            cnt = g-k
            # while (0 <= k < n):
            #     if(tail[k].startswith(query)):
            #         if len(tail[k]) == length:
            #             cnt += 1
            #         k += 1
            #     else:
            #         break
            answer.append(cnt)
        else:
            query = i.rstrip("?")
            k = bsl(0,len(arr[len(i)])-1,query,arr[len(i)])
            query2 = i.replace('?','z')
            #print(query2)
            g = bsl(0,len(arr[len(i)])-1,query2,arr[len(i)])
            cnt = g-k
            # while (0 <= k < n):
            #     if(head[k].startswith(query)):
            #         if len(head[k]) == length:
            #             cnt += 1
            #         k += 1
            #     else:
            #         break  
            answer.append(cnt)
    return answer

#print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],["fro??", "????o", "fr???", "fro???", "pro?","?????"]))