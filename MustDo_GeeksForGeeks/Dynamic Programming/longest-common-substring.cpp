/*
	Longest Common Substring
	Find length
*/

/*
	Modification of Longest common subsequence O(n^2)
	Notice that for LCS,
	If a[i] == b[j] then we can simply recurse for 1 + rec(i-1, j-1)
	Else we recurse both choices and return max(rec(i, j-1), rec(i-1, j))

	But Since this is substring,
	We cannot recurse for the else part and that is to be zero.

	And the substring can end at any i,j so iterative code makes for sense

	for i -> 1:n
		for j -> 1:m
			if a[i] == b[j]:
				dp(i, j) = 1 + dp(i-1, j-1) // It itself is common and can attach to left if any
			else:
				dp(i, j) = 0
			end if
		end for
	end for

	Answer will be max over all dp(i, j) pairs
*/

int n, m;
string a, b;

void cp()
{
    cin >> n >> m >> a >> b;
    int dp[n][m];
    clr(dp, 0);
    // substring of a ending at i
    for(int i = 0; i < n; i++)
    {
        //substring of b ending at j
        for(int j = 0; j < m; j++)
        {
            //If they are same then we can attach them to previous substring
            //of both strings
            if(a[i] == b[j])
            {
                dp[i][j] = 1;
                if(i > 0 && j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mx = max(mx, dp[i][j]);
    cout << mx << endl;
}
