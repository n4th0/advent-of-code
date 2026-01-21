
result = 0

already = []


def keep(i:int, j: int, mat:list[str]):
    global result, already

    if i == len(mat) -1 or (i+1, j) in already:
        return

    if mat[i+1][j] == '^':
        result += 1
        already.append((i, j))
        keep(i+1, j+1, mat)
        keep(i+1, j-1, mat)
        return

    keep(i+1, j, mat)



with open('input.txt', 'r') as file:

    mat = [i.strip() for i in file.readlines()]

    keep(0, int(len(mat[0])/2), mat)

    print(result)
    # print(already)



