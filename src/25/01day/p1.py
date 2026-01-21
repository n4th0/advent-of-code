
result = 0


def compute(curr: int, mov : int, dir: str ) -> int:

    mov = mov % 100

    if dir == 'R':
        curr += mov
    else: 
        curr -= mov

    if curr > 99:
        curr -= 100

    if curr < 0:
        curr += 100

    return curr







with open('input.txt', 'r') as file:
    curr = 50

    for line in file:
        curr = compute(curr, int(line[1:]), line[0])
        if curr == 0:
            result += 1
        print(curr)



print(result)


