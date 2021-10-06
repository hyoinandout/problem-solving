def rotateMat(mat):
    for i in mat:
        i.reverse()
    mat.reverse()
    return mat

# print(rotateMat([[1,3,4],[2,4,6],[6,2,6]]))
# print(rotateMat([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))
# print(rotateMat([[11,2,6,4,7],[4,1,6,5,15],[7,4,9,10,16],[18,7,7,3,13],[2,7,6,8,13]]))

