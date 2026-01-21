
result = 0

with open('input.txt', 'r') as file:
    arr = file.readline().strip().split(',')



    for rang in arr:

        a_st, b_st = rang.split('-')

        a = int(a_st)
        b = int(b_st)

        while a != (b + 1):
            a_st = str(a)


            for size in range(1, len(a_st)):
                if len(a_st) % size == 0:
                    chunk = [a_st[i:i+size] for i in range(0, len(a_st), size)]
                    # print(chunk) # combinations considered

                    if all(x == chunk[0] for x in chunk):
                        result += a
                        # print(a)
                        break




            a +=1 


print(result)
