
result = 0

with open('input.txt', 'r') as file:


    data = file.readlines()

    n = 0

    ranges = []
    for i, nums in enumerate(data):
        if len(nums) == 1:
            n = i + 1
            break

        a,b = nums.strip().split('-')
        ranges.append((int(a), int(b)))


    nums = []

    for a in range(n, len(data)):
        nums.append(int(data[a]))


    for num in nums:
        for x, y in ranges:
            if num >= x and num <= y:
                result += 1
                break





print(result)
