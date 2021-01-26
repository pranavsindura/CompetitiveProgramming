/*
	0/1 Knapsack Problem
	Given Capacity W
	List of values and weights
	maximize value such that total weight of items is atmost W
*/

/*
	Approach 1 - Check all subsets O(2^n)
	Approach 2 - DP
		We'll make a 2D DP
		dp(i, j) => Maximum value obtained using first i items and current weight j
		Transitions:
			If we pick this item, we'll gain value val[i]
			And previously weight must be j - wt[i]

			dp(i, j) = max( dp(i,j), dp(i-1, j - wt[i]) + val[i] )

			If we don't pick this item

			dp(i, j) = max( dp(i,j), dp(i-1, j) )
*/

int dp[1005][1005];
void cp()
{
    int n, w;
    cin >> n >> w;
    vector<int> val(n + 1), wt(n + 1);
    for(int i = 0; i < n; i++)
        cin >> val[i + 1];
    for(int i = 0; i < n; i++)
        cin >> wt[i + 1];
    
    clr(dp, 0);
    // Fill bag upto weight j, using the first i items
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            // pick ith item, prev wt must be j - wt[i], val is added
            if(j >= wt[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i]] + val[i]);
            //dont pick, val is not added
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[n][w] << endl;
}
