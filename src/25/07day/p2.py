dic = {}


def keep(i:int, j: int, mat:list[str]):

    if i == len(mat)-1:
        return 1

    if dic.get((i,j)) is not None:
        return dic[i, j]


    if mat[i+1][j] == '^':
        val =  keep(i+1, j+1, mat) + keep(i+1, j-1, mat)
        dic[(i, j)] = val
        return val

    return keep(i+1, j, mat)



with open('input.txt', 'r') as file:

    mat = [i.strip() for i in file.readlines()]

    print(keep(0, int(len(mat[0])/2), mat))
    # print(dic)



