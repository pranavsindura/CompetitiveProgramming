/*
	Find the number of ways to make a change N
	given coins of different denomination
*/
/*
	Approach - Recursion with Memo

	We hold 2 states, the Change we have to make, the coin index we are at
	We have 2 choices, we can either continue using this coin
	Or we can go to the next coin
	Sum up both ways and return
*/

ll dp[305][1005];
ll solve(int C, int i, vector<int> &arr)
{
    if(C < 0)
        return 0;
    if(C == 0)
        return 1;
    if(i == sz(arr))
        return 0;
    ll &ret = dp[C][i];
    if(~ret)
        return ret;
    ll ways = solve(C - arr[i], i, arr) + solve(C, i + 1, arr);
    return ret = ways;
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int C;
    cin >> C;
    clr(dp, -1);
    ll ans = solve(C, 0, arr);
    cout << ans << endl;
}