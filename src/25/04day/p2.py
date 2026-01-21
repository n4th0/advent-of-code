
result = 0



def calculateRolls(matr, i, j):
    res = 0

    directions = [(0,1),(1,1),(1,0),
        (0,-1),(-1,-1),(-1,0),
        (-1,1),(1,-1) ]

    for direction in directions:
        i_aux, j_aux = i+direction[0], j + direction[1]

        if i_aux >= 0 and j_aux >= 0 and j_aux < len(matr[0]) and i_aux < len(matr) and matr[i_aux][j_aux] == '@':
            res += 1

    return res

with open('input.txt', 'r') as file:

    # mat = file.readlines()

    mat = [list(line.strip()) for line in file]



    while True:

        next = 0
        
        pos = []

        for i, line in enumerate(mat):
            for j, x in enumerate(line):
                if x != '.' and calculateRolls(mat, i, j) < 4:
                    pos.append((i, j))
                    next += 1
                    result+= 1

        for i, j in pos:
            mat[i][j] = "."

        if  next  == 0:
            break




    # print(len(mat))
    # print(len(mat[0]))

    # for i in mat:
    #     for j in i:
    #         print(j, end="")
    #     print()


print(result)
