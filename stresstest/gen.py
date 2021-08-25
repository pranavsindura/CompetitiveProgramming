from random import randint, shuffle

TC = 10
print(TC)
while TC > 0:
	n = randint(2, 5)
	arr = [randint(1, 10) for i in range(n)]
	q = randint(1, 3)

	Type = []
	U = []
	V = []

	for i in range(q):
		t = randint(1, 2)
		Type.append(t)
		if t == 1: # Change value of A[u]
			u = randint(1, n)
			v = randint(1, 10)
			U.append(u)
			V.append(v)
		else: # Move u to the right of v
			u = randint(1, n - 1)
			v = randint(u + 1, n)
			if randint(0, 1):
				u,v = v,u
			U.append(u)
			V.append(v)


	print(n)
	print(*arr)
	print(q)
	print(*Type)
	print(*U)
	print(*V)

	TC -= 1

