/*
	Path in Matrix

	Find path in matrix with maximum value If you start from any column in row 0 and go to any column in row n-1
	from cell (i,j) you can go
	(i+1, j)
	(i+1, j-1)
	(i+1, j+1)
*/

/*
	Approach - DP O(n^2) time O(n^2) time

		We can initialise values for the first row
		For every cell we can come from 3 places, maximise path
*/
void cp()
{
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    int dp[n][n];
    clr(dp, 0);

    for(int i = 0; i < n; i++)
        dp[0][i] = arr[0][i];
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // for (i,j) I can come from 3 directions
            // (i-1, j), (i-1, j-1), (i-1, j+1)
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
            if(j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
            if(j + 1 < n)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + arr[i][j]);
        }
    }
    cout << *max_element(dp[n - 1], dp[n - 1] + n) << endl;
}
