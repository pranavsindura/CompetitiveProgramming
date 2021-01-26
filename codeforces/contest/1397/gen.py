from random import randint

n = randint(3, 20);
print(n)
for _ in range(n):
	print(randint(1,100), end=" ")