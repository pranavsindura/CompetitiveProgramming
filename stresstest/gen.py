from random import randint

q = 3 * 10 ** 6
while q > 0:
	t = randint(1, 4)
	x = randint(1, 10)
	print(t, x)
	q -= 1
print(-1)