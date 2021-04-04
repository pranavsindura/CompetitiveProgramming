/*
	Algebra

	Will add headings later, this is the stuff I know so far

	Finding Values	

	1) 	Ax < B
		x < B/A
		Largest x = ceil(B / A) - 1

	2) 	Ax <= B
		x <= B/A
		Largest x = floor(B / A)

	3) 	Ax > B
		x > B/A
		Largest x = floor(B / A) + 1

	2) 	Ax >= B
		x >= B/A
		Largest x = ceil(B / A)





	Extended Eucliean GCD Algorithm

	Finds GCD of A, B and also finds a solution (both x and y) to
	Ax + By = gcd(A, B)






	Linear Diophantine Equation
	A = 0, B = 0 is a corner case, depends of C = 0 or not

	Finding Solutions to
	Ax + By = C
	
	Solution only exist if gcd(A, B) divides C
	let G = gcd(A, B)

	Now, find a solution to

	A x' + B y' = G

	This can be done with Extended Euclidean GCD Algorithm

	Once you have a solution, multiply both sides by C/G
	x = x' * C/G
	y = y' * C/G

	we will get back our previous eqn

	Ax + By = C

	Getting other solutions,

	x = x0 + k * B/G
	y = y0 - k * A/G

	k can be any integer

	This is how we can generate any other equivalent solution


	Representable numbers as
	Ax + By (x > 0, y > 0)
	in [left, right]

	Obviously, any number not divisible by GCD(A, B) can not be represented as 
	A * x + B * y
	so we can divide A, B, left, and right by GCD(A, B) and get the same problem with 
	A and B being relatively prime. 
	(Notice that left should be rounded up and right should be rounded down after the division.)

	Now, it can be proven that any number greater than or equal to 2 * A * B can be 
	represented as A * x + B * d. 
	Here is a hint for the proof: for every such number N,
	N mod A = (B * d) mod A
	N mod B = (A * x) mod B
	and since A and B are relatively prime, we can find values for x and d such that 
	1 ≤ d ≤ A and 1 ≤ x ≤ B that satisfy those two equations.
	
	To find out if the numbers less than 2 * A * B can be represented in the form
	A * x + B * d, we can use the fact that for every such representation we can reduce 
	x by B and correspondingly increase d by A to get the same sum. 
	Thus, we only need to check values from 1 to B for x.



	Modular Arithmetic

	Basic Properties

	(a + b) % N = (a%N + b%N) % N
	(a - b) % N = (a%N - b%N + N) % N
	(a * b) % N = (a%N * b%N) % N
	


	Modular Inverse
	(a / b) mod N = a * inv(b) mod N

	- 	If N is prime

		we can use Fermat's Little Theorem
		inv(A) = pow(A, N - 2)

		Euler's Theorem
		inv(A) = pow(A, phi(N) - 1)

	-	If N is not prime, inverse may or may not exist

		Ax = 1 mod N

		We can solve,
		Ax + Ny = 1 
		
		This is a Linear diophantine equation,

		Obviously gcd(A, N) = 1 for inverse to exist

		Solve it using Extended Euclidean GCD Algorithm
		Find x, y

		inv(A) = x mod N, x may be negative
			   = (x % N + N) % N; 

	Some properties

	If you start at A and move through all positions in steps of K, mod N
	Then you will visit all positions which are of form
	It can be viewed as an offset of A

	A + x * gcd(K, N) mod N

	There will be N / gcd(K, N) such positions

	- 	the smallest position will be
		A mod N

	-	The largest position will be < N and can be found by solving the
		inequality

		(A mod N) + xB < N
		x < [N - (A mod N)] / B



	If A = 0, then we can say that we visit all positions that are multiples of gcd(K, N)


	Suppose you want to find the Time (smallest) of reaching a certain position C
	Then we will need to solve

	A + x * gcd(K, N) = C mod N
	or (B = gcd(K, N))
	A + Bx = C mod N
	or
	Bx = (C - A) mod N
	This is now a Linear Congruence which we have to solve, more on that later




	Linear Congruence

	Ax = B mod N
	
	-	By finding Inverse

		x = B * inv(A) mod N
		Find inv(A)

		We see that B must be a multiple of g = gcd(A, N) [from properties above]
		else inverse does not exist
		Also we must make gcd(A, N) = 1 to find the inverse

		A' = A / g
		B' = B / g
		N' = N / g

		A'x = B' mod N'

		now gcd(A', N') = 1

		find
		x = B' * inv(A') mod N'
		find inv(A'), then find x
		x will be smallest solution

		other solutions will be of form

		x = (x0 + i * N') mod N, where i E [0, g - 1]


	-	Linear Diophantine Equation
		rewrite as,

		Ax + Ny = B
		Solve this



	Primitive Roots

	r is called a primitive root of N
	iff r^1, r^2, ..., r^(N-1) mod N are all distinct numbers

	if r is a primitive root then the smallest number k s.t.
	r^k = 1 mod N
	is
	k = phi(N) [Euler's totient function]

	There are phi(phi(N)) primitive roots of N

	To check if r is candidate for being a primitive root- (SPOJ PROOT)
	Find phi(N)
	Find prime factors of phi(N) -> p1, p2, ..., pk

	r^(phi(N) / p_i) mod N != 1 for all i E [1, k] must hold

	Discrete Log


	Links:
	https://codeforces.com/blog/entry/60562?#comment-445168
	AGC026-B
	ABC186-E
	SPOJ PROOT

*/