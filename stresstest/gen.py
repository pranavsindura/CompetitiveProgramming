from random import randint
import math

lookup_max = []
lookup_min = []

def build_min(arr, n):
    for i in range(0, n): 
        lookup_min[i][0] = arr[i] 
      
    j = 1
    while (1 << j) <= n: 
        i = 0
        while (i + (1 << j) - 1) < n: 
            if (lookup_min[i][j - 1] <  lookup_min[i + (1 << (j - 1))][j - 1]): 
                lookup_min[i][j] = lookup_min[i][j - 1] 
            else:
                lookup_min[i][j] = lookup_min[i + (1 << (j - 1))][j - 1] 
              
            i += 1
        j += 1        
  
def rmin(L, R): 
    j = int(math.log2(R - L + 1)) 
    if lookup_min[L][j] <= lookup_min[R - (1 << j) + 1][j]: 
        return lookup_min[L][j] 
    else:
        return lookup_min[R - (1 << j) + 1][j] 


def build_max(arr, n):
    for i in range(0, n): 
        lookup_max[i][0] = arr[i] 
      
    j = 1
    while (1 << j) <= n: 
        i = 0
        while (i + (1 << j) - 1) < n: 
            if (lookup_max[i][j - 1] >  lookup_max[i + (1 << (j - 1))][j - 1]): 
                lookup_max[i][j] = lookup_max[i][j - 1] 
            else:
                lookup_max[i][j] = lookup_max[i + (1 << (j - 1))][j - 1] 
              
            i += 1
        j += 1        
  
def rmax(L, R): 
    j = int(math.log2(R - L + 1)) 
    if lookup_max[L][j] <= lookup_max[R - (1 << j) + 1][j]: 
        return lookup_max[L][j] 
    else:
        return lookup_max[R - (1 << j) + 1][j] 

TC = 10
print(TC)
while TC > 0:
	N = randint(1, 100000)
	MAXH = randint(1, 10**9)
	M = randint(1, 100000)

	print(N)
	print(MAXH)
	print(M)

	L = []
	R = []
	A = []
	B = []

	is_random = False
	if randint(1, 100) <= 10:
		is_random = True

	if is_random == True:
		for i in range(M):
			L.append(randint(1, N))
			R.append(randint(L[-1], N))
			A.append(randint(1, MAXH))
			B.append(randint(A[-1], MAXH))
	else:
		mn = []
		mx = []
		lookup_max = [[0 for i in range(25)] for j in range(N)]
		lookup_min = [[0 for i in range(25)] for j in range(N)]
		for i in range(N):
			mn.append(randint(1, MAXH))
			mx.append(randint(mn[-1], MAXH))
		build_min(mn, N)
		build_max(mx, N)

		for i in range(M):
			L.append(randint(1, N))
			R.append(randint(L[-1], N))
			A.append(randint(1, rmin(L[-1] - 1, R[-1] - 1)))
			B.append(randint(rmax(L[-1] - 1, R[-1] - 1), MAXH))

	print(*L)
	print(*R)
	print(*A)
	print(*B)
	TC -= 1