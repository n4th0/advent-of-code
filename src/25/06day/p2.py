

result = 0

with open('input.txt', 'r') as file:

    arr = file.readlines()

    # arr = [i.strip() for i in arr]

    mat = arr[:len(arr) -1]

    # for a in arr:
    #     mat.append(list(filter(lambda x: len(x) != 0, a.split(" "))))


    mat = list(map("".join, zip(*mat))) # transpose
    # print([b.strip() for b in mat])

    mat = [i.strip() for i in mat]

    op = list(filter(lambda x: len(x) != 0, [i.strip() for i in arr[len(arr) -1]]))

    i = 0
    acum = 0 if op[0] is '+' else 1
    for elem in mat:
        if len(elem) == 0:
            i+= 1
            result += acum
            if i == len(op):
                break

            if op[i] == '*':
                acum = 1
            else:
                acum = 0

            continue

        if op[i] == '*':
            acum *= int(elem)
        else:
            acum+= int(elem)









print(result)
