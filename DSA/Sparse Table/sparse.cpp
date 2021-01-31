/*
	SPARSE TABLE

	Immutable Arrays
	Associativity

	O(logn) range queries
	O(1) range queries if function is Idempotent f(x, x) = x, eg - min(), gcd()

	IDEA

	We can represent any number as summation of powers of 2, aka Binary Representation
	13 = 8 + 4 + 1
	There are at most ceil(log2(N)) summands

	Therefore we can also represent a range as summation of disjoint ranges whose length is a power of 2

	[2, 14] => [2, 9] U [10, 13] U [14, 14]
	   13         8        4          1

	Thus we can precompute answers for each starting position i and a length which is a pwoer of 2
	This can be conveniently calculated using DP as

	val[i][2^j] = f(val[i][2^(j - 1)], val[i + 2^(j - 1)][2^(j - 1)]

	In simple terms
	the value of a 8 length range starting from i can be calculated
	by combining the values of a 4 length range starting with i and 4 length range starting from i+4-1

	APPLICATIONS

	1. Range Sum queries
		There is prefix sum for this but sparse table + range sum helps understand the concept
		[L, R]
		Loop on power of 2 starting from biggest
		if 2^K <= length of the range
		combine the value of the range starting from L having length 2^k
		Then continue processing the smaller interval

		for K in range(ceil(log2(N)) => 0):
			if 2^K <= R-L+1:
				sum += val[L][K]
				L += 2^K

	2. Range Minimum Query
		min() is an idempotent function
		min(x, x) = x
		so even if we repeat some values it does not change the answer

		So we can use a simple hack!

		Say we want min in range [L, R]
		We can break the range into 2 overlapping parts where each part has a length
		equal to the highest power of 2 <= R-L+1 => K
		that power of 2 is basically ceil(log2(R - L + 1))

		then the answer is simply min(val[L][K], val[R - 2^K + 1][K])
		We repeat some values but it does not matter!

		This does require us to quickly compute ceil(log2()) which can be precomputed as well

		log2[1] = 0
		for i in range(1 => N):
			log2[i] = log2[i/2] + 1

	3. Range GCD
		same as above, gcd() is an idempotent function

	4. Kth ancestor / child of a node in a Rooted Tree
		Use the idea similar to above
		the 2nd ancestor of a node is 1st ancestor of the node's first ancestor
		OR
		the 2^j ancestor of the node is the 2^(j-1) ancestor of the 2^(j-1) ancestor of this node

		p[i][j] = p[p[i][j - 1]][j - 1]
		where p[i][j] is the 2^j th ancestor of node i

		to find the Kth ancestor of a node
		similar to range sum query
		keep going in descending order of powers of 2
		and break K into powers of 2 and keep finding the corresponding ancestors

		P = U
		for i in range(ceil(log2(N)) => 0):
			if ith bit is 1 in K
				P = p[P][i]


	5. LCA in a Rooted Tree

*/

// Build log2
int lg[MAXN];
void init()
{
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

using ftype = int;
const int K = 25; // Enough for any array
ftype st[MAXN][K + 1];

ftype combine(ftype L, ftype R)
{

}

void build(vector<ftype> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
            st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// Query for idempotent Functions
ftype query(int L, int R)
{
    int j = lg[R - L + 1];
    return combine(st[L][j], st[R - (1 << j) + 1][j]);
}

// Query for normal Functions
ftype query(int L, int R)
{
    ftype ans = e; // Initial value
    for(int j = K; j >= 0; j--)
        if((1 << j) <= R - L + 1)
            ans = combine(ans, st[L][j]), L += 1 << j;
    return ans;
}