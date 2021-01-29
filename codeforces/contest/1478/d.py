def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a%b)
    
for _ in range (int(input())):
  n,k = map(int, input().split())
  arr = list(map(int, input().split()))
  arr.sort()
  g = 0
  for i in range(n-1):
    diff = arr[i+1]-arr[i]
    g = gcd(g, diff)
  off = arr[0] % g

  if k % g == off:
    print("YES")
  else:
    print("NO")