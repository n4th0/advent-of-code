

result = 0


def max(a:int, b:int) -> int:
    return a if a > b else b



with open('input.txt', 'r') as file:

    for line in file:

        line = line.strip()
        maxValue = 0
        for i, a in enumerate(line):
            for b in line[i+1:]:
                val = int(a+b)
                maxValue = max(maxValue, val)

        result += maxValue



print(result)




