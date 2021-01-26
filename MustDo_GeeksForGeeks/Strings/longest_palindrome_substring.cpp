/*
    LONGEST PALINDROMIC SUBSTRING
*/

/*
    Approach 1 - Traverse All Substring and check O(n^3)

    Approach 2 - Use Recursion with memoization O(n^2) time O(n^2) space

    See overlapping subproblems and Optimal Substructure

    To See if i...j is palindome ->
    if s[i] == s[j] -> check is i+1....j-1 is a palindrome
    else i...j is not a palindrome

    Approach 3 - Pick a center and expand O(n^2) time O(1) space
    Find even length palindrome by picking two same adjacent characters and expanding in both direction
    Find odd length palindrome by picking one character and expanding in both direction
    Keep track of maximum palindrome so far
*/

//Approach 2
#define pi pair<int,int>
#define ff first
#define ss second
#define clr(x,v) memset(x, v, sizeof(x))
const int MAXN = 1e3 + 5;

int dp[MAXN][MAXN];

bool is_palin(int i, int j, string &s)
{
    if(~dp[i][j])
        return dp[i][j];
    if(i >= j)
        return dp[i][j] = 1;
    if(s[i] == s[j])
        return dp[i][j] = is_palin(i + 1, j - 1, s);
    else
        return dp[i][j] = 0;

}

void cp()
{
    clr(dp, -1);
    string s;
    cin >> s;
    int n = ln(s);
    pi ans = {0, 0};
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(is_palin(i, j, s))
            {
                if(j - i + 1 > ans.ss - ans.ff + 1)
                    ans = {i, j};
            }
        }
    }
    string ans_str;
    for(int i = ans.ff; i <= ans.ss; i++)
        ans_str += s[i];
    cout << ans_str << endl;
}

//Approach 3
void cp()
{
    string s;
    cin >> s;
    int n = ln(s);
    pi ans = {0, 0};
    //find odd length palindrome
    for(int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            if(r - l + 1 > ans.ss - ans.ff + 1)
                ans = {l, r};
            else if(r - l + 1 == ans.ss - ans.ff + 1 && l <= ans.ff)
                ans = {l, r};
            l--, r++;
        }
    }
    //find even length palindrome
    for(int i = 0; i < n - 1; i++)
    {
        int l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            if(r - l + 1 > ans.ss - ans.ff + 1)
                ans = {l, r};
            else if(r - l + 1 == ans.ss - ans.ff + 1 && l <= ans.ff)
                ans = {l, r};
            l--, r++;
        }
    }
    string ans_str;
    for(int i = ans.ff; i <= ans.ss; i++)
        ans_str += s[i];
    cout << ans_str << endl;
}