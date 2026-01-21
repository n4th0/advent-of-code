
result = 0



def calculateRolls(matr, i, j):
    res = 0

    directions = [(0,1),(1,1),(1,0),
        (0,-1),(-1,-1),(-1,0),
        (-1,1),(1,-1) ]

    for direction in directions:
        i_aux, j_aux = i+direction[0], j + direction[1]
        # print(str(i_aux) + " " + str(j_aux))

        if i_aux >= 0 and j_aux >= 0 and j_aux < len(matr[0]) and i_aux < len(matr) and matr[i_aux][j_aux] == '@':
            # print(str(i_aux) + " " + str(j_aux))
            res += 1

    return res







with open('input.txt', 'r') as file:

    mat = file.readlines()

    mat = [i.strip() for i in mat]

    calculateRolls(mat, 0, 0)

    for i, line in enumerate(mat):
        for j, x in enumerate(line):
            if x != '.' and calculateRolls(mat, i, j) < 4:
                # print('x', end="")
                result+= 1
                # print(x,end="")
        # print()


    # print(len(mat))
    # print(len(mat[0]))



print(result)
