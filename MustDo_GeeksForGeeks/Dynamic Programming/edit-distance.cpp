/*
	Convert string A into string B using the following operations
	1. Insert
	2. Delete
	3. Replace
*/
/*
	Approach - Recursion + Memo
		We compare the ith index of A and jth index of B
		If they are same we dont need to edit them
		If they are not then we need to edit them
		We can either delete ith character => goto i+1, j
		We can insert jth character at i => goto i, j+1
		We can replace ith character with jth character => goto i+1, j+1
*/

int n, m;
string a, b;
int dp[105][105];
int solve(int i, int j)
{
    if(i == n)
        return m - j;
    if(j == m)
        return n - i;
    if(~dp[i][j])
        return dp[i][j];

    if(a[i] == b[j])
        return dp[i][j] = solve(i + 1, j + 1);
    else
        //(i+1,j) => delete ith character
        //(i,j+1) => insert jth character
        //(i+1,j+1) => replace ith character with jth character
        return dp[i][j] = 1 + min({solve(i + 1, j), solve(i, j + 1), solve(i + 1, j + 1)});
}

void cp()
{
    cin >> n >> m;
    cin >> a >> b;
    clr(dp, -1);
    cout << solve(0, 0) << endl;
}