from functools import cache

result = 0

def calc(a,b):
    return (abs(a[0]-b[0]) +1) * (abs(a[1]-b[1])+1)



def punto_en_segmento(px, py, ax, ay, bx, by):
    # return (px,py) in perimetro

    if (ax <= px <= bx or bx <= px <= ax) and \
       (ay <= py <= by or by <= py <= ay):
        return (bx - ax) * (py - ay) == (by - ay) * (px - ax)
    return False

# hay que checkear esto
@cache
def punto_dentro_poligono(p: tuple[int,int]) -> bool:
    global pos

    px, py = p
    n = len(pos)
    cruces = 0

    for i in range(n):
        ax, ay = pos[i]
        bx, by = pos[(i + 1) % n]

        if punto_en_segmento(px, py, ax, ay, bx, by):
            return True

        if (ay > py) != (by > py):
            x_interseccion = ax + (py - ay) * (bx - ax) / (by - ay)

            if x_interseccion > px:
                cruces += 1

    return cruces % 2 == 1




def func(val) -> int:
    if val == 0:
        return 0
    if val < 0:
        return 1
    return -1

def createSquarePerimeter(a,b):
    pos = [a,b,(a[0],b[1]),(b[0], a[1])]
    n = len(pos)
    perimeter = []
    for i, p in enumerate(pos):
        pNext = pos[(i+1) % n]
        vect = (func(p[0]-pNext[0]), func(p[1]-pNext[1]))
        while p != pNext:
            perimeter.append(p)
            p = (p[0]+vect[0], p[1]+vect[1])
    return perimeter

def max(a,b):
    return a if a > b else b

def min(a,b):
    return a if a < b else b

with open('input.txt', 'r') as file:

    arr = file.readlines()
    arr = [i.strip() for i in arr]
    arr = [i.split(',') for i in arr]
    pos = [(int(i[0]), int(i[1])) for i in arr]

    dic = {}
    n = len(pos)

    # creo el permietro
    perimiter = []
    for i, p in enumerate(pos):
        pNext = pos[(i+1) % n]
        vect = (func(p[0]-pNext[0]), func(p[1]-pNext[1]))
        while p != pNext:
            perimiter.append(p)
            p = (p[0]+vect[0], p[1]+vect[1])


    rect = []
    for i in pos:
        for j in pos:
            if i == j:
                break
            rect.append((i,j))


    rect.sort(key=lambda x: calc(x[0], x[1]), reverse=True)


    for n,i in enumerate(rect):


        factible = True

        a = i[0]
        b = i[1]

        vert = [a,b,(a[0],b[1]),(b[0], a[1])]
        aux = len(vert)

        if n % 100 == 0:
            print(str(n) + "/" + str(len(rect)))

        for d, p in enumerate(pos):
            pNext = vert[(d+1) % aux]
            vect = (func(p[0]-pNext[0]), func(p[1]-pNext[1]))
            while p != pNext:

                if not punto_dentro_poligono(p):
                    factible = False
                    break


                p = (p[0]+vect[0], p[1]+vect[1])
            if not factible:
                break


        if factible:
            result = calc(i[0], i[1])
            break










    print(result)

