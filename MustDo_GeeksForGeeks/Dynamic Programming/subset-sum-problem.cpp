/*
	Find of the array can be divided into 2 subsets with equal sum
*/

/*
	Approach - DP
		We can convert this into a knapsack like problem

		Find number of ways to make sum/2 total using array values
		if sum is odd then there is no way
		else we can find the number of ways to make sum = sum/2
		If even 1 way exists, then remaining subset can also form sum/2
*/

int dp[101][1000 * 100 + 1];
void cp()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++)
        cin >> arr[i + 1], sum += arr[i + 1];
    if(sum & 1)
    {
        // If sum is odd, we can't partition
        cout << "NO\n";
        return;
    }
    int half = sum / 2;
    clr(dp, 0);
    dp[0][0] = 1;
    // number of ways to make sum j using only first i elements
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            // use the ith element to make sum j
            // prev needs to be j - arr[i]
            if(j - arr[i] >= 0)
                dp[i][j] += dp[i - 1][j - arr[i]];
            dp[i][j] += dp[i - 1][j];
        }
    }
    // If there exists a way to form half
    // then remaining elements can also form half
    if(dp[n][half])
        cout << "YES\n";
    else
        cout << "NO\n";
}