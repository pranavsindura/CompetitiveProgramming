def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)

n, a, b = map(int, input().split())

g = gcd(a,b)
lcm = a*b//gcd(a,b)

mul = n//lcm

extra = mul * (min(a,b) - 1)

last = mul*lcm
left = n-last
total = mul + extra + min(min(a,b)-1, left)
total = min(total, n)


g = gcd(total, n)
total = total//g
n = n//g
print(str(total) + '/' + str(n))
