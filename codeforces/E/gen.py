from random import randint
n = 10**6
k = 2**30 - 1
print(n, k)
for i in range(n):
	print(randint(1, 10**9), end=" ")
print()