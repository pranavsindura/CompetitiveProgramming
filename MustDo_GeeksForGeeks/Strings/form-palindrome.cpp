/*
	FORM A PALINDROME
	Minimum characters to insert to make string a palindrome
*/

/*
	Approach 1 - Recursion O(2^n)
	Approach 2 - Recursion with Memo O(n^2)
*/

//Approach 2
string s;

int dp[55][55];

int rec(int i, int j)
{
    if(~dp[i][j])
        return dp[i][j];
    if(i >= j)
        return dp[i][j] = 0;
    else
    {
        if(s[i] == s[j])
            return dp[i][j] = rec(i + 1, j - 1);
        else
            return dp[i][j] = min(rec(i + 1, j), rec(i, j - 1)) + 1;
    }
}

void cp()
{
    clr(dp, -1);
    cin >> s;
    cout << rec(0, ln(s) - 1) << endl;
}
