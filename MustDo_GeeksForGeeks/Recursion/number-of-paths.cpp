/*
	Number of paths from 1,1 to n,m in a matrix
*/
/*
	Approach 1 - Recursion find ways to reach n,m that'll be number of ways to reach n-1,m + n,m-1
	Approach 2 - Add Memo to above approach
	Approach 3 - Iterative DP
*/

// Approach 1+2
int dp[11][11];
int rec(int n, int m)
{
    if(~dp[n][m])
        return dp[n][m];
    if(n == 1 || m == 1)
        return dp[n][m] = 1;
    else
        return dp[n][m] = rec(n - 1, m) + rec(n, m - 1);
}
// Approach 3
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int ways[n + 1][m + 1];
        clr(ways, 0);
        for(int i = 1; i <= n; i++)
            ways[i][1] = 1;
        for(int i = 1; i <= m; i++)
            ways[1][i] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 2; j <= m; j++)
            {
                ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
            }
        }
        cout << ways[n][m] << endl;
    }
    return 0;
}