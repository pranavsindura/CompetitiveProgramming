from random import randint

t = randint(1, 1000)
print(t)
for _ in range(t):
	n = randint(1, 100)
	m = randint(1, n)
	A = []
	for i in range(n):
		A.append(randint(0, 1))

	print(n, m)
	print(*A)