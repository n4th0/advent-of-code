
result = 0

with open('input.txt', 'r') as file:
    arr = file.readline().strip().split(',')



    for rang in arr:

        a_st, b_st = rang.split('-')

        a = int(a_st)
        b = int(b_st)

        while a != (b + 1):
            a_st = str(a)

            aux = len(a_st) // 2

            if a_st[:aux] == a_st[aux:]:
                result += a

            a +=1 


print(result)
