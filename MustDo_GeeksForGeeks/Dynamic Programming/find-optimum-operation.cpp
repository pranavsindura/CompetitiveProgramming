/*
	Given N, you have to reach from 0 to N, using one of the following operations
	1. Double the number
	2. Increment by 1
*/
/*
	Approach 1 - DP (Overkill?)
		There are overlapping subproblems and an optimal substructure
		Just write a recursion with memo

		O(n) worst case

	Approach 2 - Math
		We'll go reverse, convert N to 0 by using halving and decrement
		The number can be written out in binary like
		11001000110001
		It is optimum to remove a 1 at the LSB with decrement
		If there is no 1 at LSB, we bring 1 to  LSB using Halving
		Process ends when we reach 0

		O(logn)
*/
// Approach 2
void cp()
{
    int n;
    clr(dp, -1);
    cin >> n;
    int op = 0;
    while(n)
    {
        if(n & 1)
            n--;
        else
            n /= 2;
        op++;
    }
    cout << op << endl;
}


// Approach 1
const int MAXN = 1e4 + 5;

int dp[MAXN];

int rec(int n, int target)
{
    if(n > target)
        return 1e7;
    if(~dp[n])
        return dp[n];
    if(n == target)
        return dp[n] = 0;
    else
        return dp[n] = 1 + min(rec(n * 2, target), rec(n + 1, target));

}

void cp()
{
    int n;
    clr(dp, -1);
    cin >> n;
    cout << 1 + rec(1, n) << endl;
}
