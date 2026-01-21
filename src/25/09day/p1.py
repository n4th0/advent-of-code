
result = 0

def calc(a,b):
    return (abs(a[0]-b[0]) +1) * (abs(a[1]-b[1])+1)

def max(a,b):
    return a if a > b else b

with open('input.txt', 'r') as file:

    arr = file.readlines()
    arr = [i.strip() for i in arr]
    arr = [i.split(',') for i in arr]

    pos = [(int(i[0]), int(i[1])) for i in arr]
    # pos = []
    # for i,line in enumerate(arr):
    #     for j,b in enumerate(line):
    #         if b == '#':
    #             pos.append((i,j))


    for a in pos:
        for b in pos:
            result = max(calc(a,b), result)


    print(result)

