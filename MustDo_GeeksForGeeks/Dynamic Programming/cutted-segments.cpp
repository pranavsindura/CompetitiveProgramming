/*
	Given a rod of length N
	and 3 possible lengths at which to make cuts
	Maximize the number of segments the rod can be cut into
*/
/*
	Approach - Recursion with Memo

		We can try all 3 and and see if any lead to rod length == 0
*/
int N, x, y, z;
int dp[4005];
int solve(int len)
{
    if(len == 0)
        return 0;
    if(len < x && len < y && len < z)
        return (int) -1e7;
    int &ret = dp[len];
    if(~ret)
        return ret;
    // cout<<len<<" ";
    int seg = -1e7;
    if(len >= x)
        seg = max(seg, 1 + solve(len - x));
    if(len >= y)
        seg = max(seg, 1 + solve(len - y));
    if(len >= z)
        seg = max(seg, 1 + solve(len - z));
    return ret = seg;
}

void cp()
{
    cin >> N >> x >> y >> z;
    clr(dp, -1);
    cout << solve(N) << endl;
}