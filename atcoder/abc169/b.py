n = int(input())
arr = map(int, input().split())
zero = False
ans = 1
ok = True
for e in arr:
	if e == 0:
		zero = True
	ans = ans * e;
	if ans > 10**18:
		ok = False
if zero:
	print(0)
else:
	if ok:
		print(ans)
	else:
		print(-1)
