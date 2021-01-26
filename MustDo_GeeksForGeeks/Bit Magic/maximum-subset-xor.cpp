/*
	Given a Set of numbers
	Find the Maximum XOR value of any subset
*/

/*
	Approach 1 - DP/Memo O(N * 2^k) space and time where k is the maximum length of the number in array
		For every index we have 2 choices, pick or don't pick
		Maximise the xor value

	Approach 2 - Gaussian Elimination Modulo 2 / Vector Basis
		Very standard Vector basis problem
		Find the basis of the array numbers

		For every number we look at the highest bit in the number and try
		to add it in basis, if the basis has this bit, we xor it with basis of that bit
		If basis doesnt have it we add it to the basis

		After making basis, we can loop on the basis, and try to greedily pick the highest bit who's basis is available
		and do this for every bit the answer does not have
*/

// Approach 2
void insert_vector(int mask, int basis[], int len)
{
    for(int i = len - 1; i >= 0; i--)
    {
        if((mask & 1LL << i) == 0)
            continue;

        if(!basis[i])
        {
            basis[i] = mask;
            return;
        }
        mask ^= basis[i];
    }
}

int maxSubarrayXOR(int A[], int n)
{
    // Using Vector Basis, 10 bits
    const int len = 10;
    int basis[len];
    memset(basis, 0, sizeof basis);
    for(int i = 0; i < n; i++)
    {
        insert_vector(A[i], basis, len);
    }

    int ans = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        if((ans & 1 << i))
            continue;
        if(!basis[i])
            continue;
        ans ^= basis[i];
    }
    return ans;
}

// Approach 1
int memo[55][55];
int dp(int i, int arr[], int n, int mask)
{
    if(i == n)
        return mask;
    else
    {
        if(~memo[i][mask])
            return memo[i][mask];
        return memo[i][mask] = max(dp(i + 1, arr, n, mask), dp(i + 1, arr, n, mask ^ arr[i]));
    }
}

int maxSubarrayXOR(int A[], int n)
{
    memset(memo, -1, sizeof memo);
    int ans = dp(0, A, n, 0);
    return ans;
}