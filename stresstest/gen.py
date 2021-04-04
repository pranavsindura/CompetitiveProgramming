from random import randint, shuffle

TC = 1000
print(TC)
while TC > 0:
	N = randint(1, 50)
	A = [i+1 for i in range(N)]
	shuffle(A)
	print(N)
	print(*A)
	TC -= 1