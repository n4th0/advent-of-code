
from math import sqrt

def ldistance(a,b,c,a2,b2,c2):
    return sqrt((a-a2)**2 + (b-b2)**2 + (c-c2)**2)

def mergeCircuits(a, b):
    for i in a:
        if i not in b:
            b.append(i)
    return b

def getCircuitGivenJunction(a, circuits):
    for circuit in circuits:
        if a in circuit: 
            return circuit
    return []

def inst(l, val):
    for i, (_,_,_,_,_,_,v)  in enumerate(l):
        if v > val:
            return i

    return 0

with open('input.txt', 'r') as file:

    values = [i.strip() for i in file.readlines()]

    values = [i.split(',') for i in values ]
    values = [[int(a), int(b),int(c)] for a,b,c in values]

    arr = []

    for a, b, c in values:
        # min = (0,0,0,0xFFFFFFFFFFFFF) # should be INF

        for a2, b2, c2 in values:
            if a == a2 and b == b2 and c == c2:
                continue

            dl = ldistance(a,b,c,a2,b2,c2)

            # if dl not in [d[6] for d in arr]:
            arr.append([a,b,c,a2,b2,c2,dl])


    arr = [i for j,i in enumerate(arr) if j % 2 == 0]
    # print("#"* 20)
    arr.sort(key=lambda x: x[6])

    # for i in arr:
    #     print(i)

    # O(3)
    #
    # arr2 = arr

    # for i in arr:
    #     if i[6] not in [a[6] for a in arr2]:
    #         arr2.append(i)

    # circuits = []
    #
    # for i, a in enumerate(arr):
    #
    #     a,b,c,a2,b2,c2,_ = a
    #
    #     for circuit in circuits:
    #         if (a,b,c) in circuit:
    #             circuit = merge(circuit, circuit)
    #             break
    #
    #         if (a2,b2,c2) in circuit:
    #             circuit = merge(circuit, circuit)
    #             break
    #
    #     circuits.append([(a,b,c), (a2,b2,c2)])
    #
    #     if i == 10:
    #         break

    values = [[(v[0], v[1], v[2])] for v in values]

    # print(len(arr))

    # for i in arr:
    #     print([(i[0],i[1],i[2]),(i[3],i[4],i[5]),i[6]])

    # print([[(i[0],i[1],i[2]),(i[3],i[4],i[5]),i[6]] for i in arr])


    # for el in arr:
    #     if el[6] not in [i[6] for i in arr2]:
    #         arr2.append(el)

    # for i in arr:
    #     print([(i[0],i[1],i[2]),(i[3],i[4],i[5]),i[6]])
    # print("#"*10)


    # arr = [n for i,n in enumerate(arr) if i %2 == 0]
    # print(len(arr))


    # print([[(i[0],i[1],i[2]),(i[3],i[4],i[5])] for i in arr])

    # print([len(i) for i in values])

    for i, a in enumerate(arr):
        a,b,c,a2,b2,c2,_ = a

        n1 = getCircuitGivenJunction((a,b,c),values)
        n2 = getCircuitGivenJunction((a2,b2,c2),values)

        # print(n1)
        # print(n2)

        values.remove(n2)

        if n1 != n2:
            values.remove(n1)

        values.append(mergeCircuits(n1,n2))
        # print(n1, end= ' ')
        # print(mergeCircuits(n1,n2))
        # print('-' * 10)
        #
        # for n in values:
            # print(n)

        # print('#' * 10)
        # print(i)





        if i == 999:
            # print([len(i) for i in values])
            break



    d = [len(i) for i in values]
    d.sort(key=lambda x: x,reverse=True)
    print(d[0]*d[1]*d[2])



    # print(circuits)
    # print([len(i) for i in circuits])
    # print(len(circuits))

