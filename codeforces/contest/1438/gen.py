from random import randint
n = 2 * randint(1, 20) + 1
print(n)
for _ in range(n):
	print(randint(2**20, 10**9), end=" ")
print()