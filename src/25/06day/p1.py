
from functools import reduce

result = 0
with open('input.txt', 'r') as file:

    arr = file.readlines()

    arr = [i.strip() for i in arr]

    mat = []
    for a in arr:
        mat.append(list(filter(lambda x: len(x) != 0, a.split(" "))))



    mat = list(map(list, zip(*mat))) # transpose



    for line in mat:
        if line[len(line) - 1] == '*':
            result += reduce(lambda arr, x:  arr*int(x), line[:len(line) -1], 1)
        else:
            result += reduce(lambda arr, x:  arr+int(x), line[:len(line) -1], 0)








print(result)
