from random import randint

TC = 1
# print(TC)
while TC > 0:
    n = randint(1, 1000)
    A = []
    for _ in range(n):
        A.append(randint(1, 100))

    print(n)
    print(*A)

    TC -= 1
