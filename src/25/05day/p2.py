

def max(a,b):
    return a if a > b else b

def min(a,b):
    return a if a < b else b

result = 0

with open('input.txt', 'r') as file:

    data = file.readlines()

    ranges = []
    for i, nums in enumerate(data):
        if len(nums) == 1:
            break

        a,b = nums.strip().split('-')
        a,b = int(a), int(b)
        ranges.append((a, b))


    for i, (x, y) in enumerate(ranges):
        for j, (x_2, y_2) in enumerate(ranges):

            if x >= x_2 and x <= y_2 or y >= x_2 and y <= y_2:
                ranges[i] = (min(x_2, x), max(y,y_2))
                ranges[j] = (min(x_2, x), max(y,y_2))


    unic = []
    for a, b in ranges:
        if (a, b) in unic:
            continue
        result += b-a +1 
        unic.append((a, b))











print(result)
