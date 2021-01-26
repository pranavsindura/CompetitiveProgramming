/*
	Longest Common Subsequence
	Given 2 strings
*/

/*
	Approach 1 - Recursion O(2^(n+m)) time
		solve(i, j):
			if A[i] == B[j]: //then it can form an LCS
				return 1 + solve(i-1, j-1)
			else: //it cannot form lcs but we can remove/skip 1 char from either and find its LCS and return max
				return max( solve(i-1, j), solve(i, j-1) )

	Approach 2 - Memoization O(n*m) space, O(n*m) time
		Overlapping sub problems occur during
		solve(i, j-1) and solve(i-1, j)

		solve(i-1, j-1) is overlapping for both so memoization will work
*/

int n, m;
string a, b;
int dp[105][105];
int solve(int i, int j)
{
    if(i < 0 || j < 0)
        return 0;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(a[i] == b[j])
        return ret = 1 + solve(i - 1, j - 1);
    else
        return ret = max(solve(i, j - 1), solve(i - 1, j));
}

void cp()
{
    cin >> n >> m;
    cin >> a >> b;
    clr(dp, -1);
    cout << solve(n - 1, m - 1) << endl;
}
