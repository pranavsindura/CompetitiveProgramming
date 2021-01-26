from random import randint
n = 1000
u = 15
v = 15
alphabet = 'ab'
S = ''.join(['*' for i in range(n)])
A = ''.join([alphabet[randint(0, 1)] for i in range(u)])
B = ''.join([alphabet[randint(0, 1)] for i in range(v)])
print(S)
print(A)
print(B)