for _ in range(int(input())):
	n = int(input())
	f = lambda a: a * (a+1) // 2
	p = 0
	val = 1
	while f(val * 2 - 1) <= n:
		val *= 2
		p += 1
		n -= f(val - 1)
	print(p)