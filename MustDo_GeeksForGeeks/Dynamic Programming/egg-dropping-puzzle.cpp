/*
	Egg Dropping Puzzle

	 We have N eggs and K floors, we have to find the critical floor
	 in minimum number of trials for the worst case
	 Rules -
		 1. An egg that survives a fall can be used again.
		 2. A broken egg must be discarded.
		 3. The effect of a fall is the same for all eggs.
		 4. If the egg doesn't break at a certain floor, it will not break at any floor below.
		 5. If the eggs breaks at a certain floor, it will break at any floor above.
*/

/*
	Approach - DP O(n*k) time and space
	If we have only 1 egg, we can start from 1st floor and go upto Kth floor to find the critical floor
	In worst case this will take exactly K steps

	If there is only 1 floor we can simply drop and egg and test, 1 step
	If there are 0 floors, 0 steps

	Because of the restriction on Number of eggs we cannot use binary search to minimize

	We can use a recursion with memo
	Given N eggs, K floors

	We can drop 1 egg from any of the K floors
	We have 2 outcomes,
		1. Egg breaks when thrown from ith floor
			This means we will have n-1 eggs and we only have to check the 1 => i-1 floors (i-1 floors)
		2. Egg does not break
			This means we have n eggs and we have to check i+1 => k floors (k - i) floors

		We will recursively find the answer for those substates
		Now since we have to pick answer for the worst case, we will pick the maximum of the two outcomes
		And then we will minimize the number of trials for this outcome

	Memoization can be used as there are overlapping substates and optimal substructure
*/

int dp[15][55];
int solve(int n, int k)
{
    if(k == 1 || k == 0)
        return k;
    if(n == 1)
        return k;

    int &ret = dp[n][k];
    if(~ret)
        return ret;

    int ans = 1e7;
    for(int i = 1; i <= k; i++)
    {
        int worst_trial = max(solve(n - 1, i - 1), solve(n, k - i));
        ans = min(ans, worst_trial + 1);
    }
    return ret = ans;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    clr(dp, -1);
    cout << solve(n, k) << endl;
}
