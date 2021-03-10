from random import randint

n = randint(1, 500)
A = []
for i in range(n):
	if A != []:
		choice = randint(0, 1)
		if choice == 0:
			A.append(randint(1, 5))
		else:
			A.append(A[-1])
	else:
		A.append(randint(1, 5))

print(n)
print(*A)