def histogram(case,start,end):
    if start >= end:
        return case[start]
    mid = (start + end) // 2
    candid = max(histogram(case,start,mid), histogram(case,mid+1,end))
    w,r,l = 1,1,1
    h = case[mid]
    area = candid
    while (end-start+1) > w:
        if end - r < mid:
            h = min(h,case[mid-l])                
            l+=1
            w+=1
            area = max(area, w * h)
        elif l + start > mid:
            h = min(h,case[mid+r])                
            r+=1
            w+=1
            area = max(area, w * h)
        else:
            if case[mid-l] > case[mid+r]:
                h = min(h,case[mid-l])                
                l+=1
                w+=1
                area = max(area, w * h)
            elif case[mid-l] <= case[mid+r]:
                h = min(h,case[mid+r])                
                r+=1
                w+=1
                area = max(area, w * h)
    return area

while True:
    case = list(map(int,input().split()))
    if case[0] == 0:
        break
    else:
        print(histogram(case[1:],0,case[0]-1))
