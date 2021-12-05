# 분할정복
# 전역변수

# 꼭 꼭 다시 풀어보자
import copy
index = 0
index2 = 0

def color(i,j,n,board):
    for y in range(n):
        for x in range(n):
            board[i+y][j+x] = 1

def quad(S,board,i,j,n):
    global index
    #print(index,i,j,n)
    if S[index] == 'b':
        color(i,j,n,board)
        return
    elif S[index] == 'w':
        return
    else:
        div = n//2
        for y in range(2):
            for x in range(2):
                index += 1
                quad(S,board,i+(y*div),j+(x*div),div)

def quad2(S,board,i,j,n):
    global index2
    # print(index2,i,j,n)
    if S[index2] == 'b':
        color(i,j,n,board)
        return
    elif S[index2] == 'w':
        return
    else:
        div = n//2
        for y in range(2):
            for x in range(2):
                index2 += 1
                quad2(S,board,i+(y*div),j+(x*div),div)

    # for y in range(n):
    #     for x in range(n):
    #         if S[index] == 'b':
    #             board[i+y][j+x] = 1
    # quad(S,index+1,board,i,j,n)
# def quad(S,index,board,i,n):
#     if S[index] == 'p':
#         quad(S,index+1,board,i,n//2)
#         return
#     for y in range(n):
#         for x in range(n):
#             if S[index] == 'b':
#                 board[i+ n*y + x] = 1
#     quad(S,index+1,board,i+n*n,n)

def solution(S1,S2):
    answer = 0
    resultBoard = [[0] * 32 for _ in range(32)]
    firstBoard = copy.deepcopy(resultBoard)
    secondBoard = copy.deepcopy(resultBoard)
    # firstBoard = [0] * 1024
    quad(S1,firstBoard,0,0,32)
    # for i in range(32):
    #     for j in range(32):
    #         print(firstBoard[i][j],end = ' ')
    #     print()
    # secondBoard = [0] * 1024
    quad2(S2,secondBoard,0,0,32)
    # for i in range(32):
    #     for j in range(32):
    #         print(secondBoard[i][j],end = ' ')
    #     print()
    for i in range(32):
        for j in range(32):
            if firstBoard[i][j] + secondBoard[i][j] >= 1:
                answer += 1
    # for i in range(1024):
    #     if firstBoard[i] + secondBoard[i] >= 1:
    #         answer += 1
    return answer
#print(solution("ppwwwbpbbwwbw","pwbwpwwbw"))
#print(solution("b","w"))
#print(solution("b","pwbwpwwbw"))
#print(solution("w","pwbwpwwbw"))