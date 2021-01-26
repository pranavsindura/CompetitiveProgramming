/*
	Total ways to reach Nth step
	If you can only jump 1,2,3 steps at a time
*/
/*
	Approach - DP O(n) time O(n) space

		For every step i we can come from i-1, i-2, i-3
		Sum up the number of ways
		We start at 0, so dp[0] = 1
*/
void cp()
{
    int n;
    cin >> n;
    int dp[n + 1];
    clr(dp, 0);
    
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i - 1 >= 0)
            dp[i] += dp[i - 1];
        if(i - 2 >= 0)
            dp[i] += dp[i - 2];
        if(i - 3 >= 0)
            dp[i] += dp[i - 3];
    }
    cout << dp[n] << endl;
}