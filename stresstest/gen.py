from random import randint, shuffle

TC = 10
print(TC)
while TC > 0:
	n = randint(2, 1000)
	s = ''
	for i in range(n):
		s += chr(randint(0, 1) + 48)

	x = randint(1, n // 2)

	print(n)
	print(s)
	print(x)

	TC -= 1

