from random import randint

n = 10000
h = randint(0, 1e8)

print(n, h)
for i in range(n):
	print(randint(0, 1e8), end = ' ')
print()