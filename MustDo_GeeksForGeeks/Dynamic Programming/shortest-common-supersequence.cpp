/*
	Shortest Common supersequence
	Find Smallest length of the string which contains both strings S1 and S2 as a subsequence
*/

/*
	Approach 1 -
		Modification on LCS
		Ans is actually n + m - len(LCS)

	Approach 2 - Recursion + Memo
		We have two pointer i,j for each string
		If A[i] == B[j]
			We need to include only one of them in the SCS
			1 + solve(i+1, j+1)
		else
			We have 2 choices
			1. Either include only A[i] and then solve for i+1, j
				1 + solve(i+1, j)
			2. Do the above for B[j]
				1 + solve(i, j+1)
			Pick minimum
*/

// Approach 2
string a, b;
int dp[105][105];
int rec(int i, int j)
{
    if(i == ln(a))
        return ln(b) - j;
    if(j == ln(b))
        return ln(a) - i;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(a[i] == b[j])
        return ret = 1 + rec(i + 1, j + 1);
    else
        return ret = min(
    {
        1 + rec(i, j + 1),
        1 + rec(i + 1, j)
    });
}

void cp()
{

    cin >> a >> b;
    clr(dp, -1);
    cout << rec(0, 0) << endl;
}