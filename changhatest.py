def treeSum(t):
    

def cal(r1, r2, lv):
    if r1.data=='b' or r2.data=='b':
        return 이lv의b넓이
    if r1.data=='w' and r2.data=='w':
        return 0
    
    if r1.data=='p' and r2.data=='p':
        tmp = 0
        for i in range(4):
            tmp += cal(r1.i번째child, r2.i번째child, lv+1)
        return tmp
    
    if r1.data=='p':
        return treeSum(r1)
    else:
        return treeSum(r2)
    
print(cal(tree1, tree2, 0))