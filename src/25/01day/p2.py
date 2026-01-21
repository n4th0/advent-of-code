
result = 0


def rotateR(curr: int) -> int:
    if curr == 99:
        return 0
    else:
        return curr + 1

def rotateL(curr: int) -> int:
    if curr == 0:
        return 99
    else:
        return curr - 1







with open('input.txt', 'r') as file:
    curr = 50

    for i,line in enumerate(file):
        num = int(line[1:])

        while num != 0: # brute force, I should check 
        # how the hell should i use the module
            if line[0] == 'R':
                curr = rotateR(curr)
                num -=1
            else:
                curr = rotateL(curr)
                num -=1
            if curr == 0:
                result += 1




print(result)


