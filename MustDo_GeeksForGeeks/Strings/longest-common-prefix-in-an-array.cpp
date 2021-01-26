/*
	LONGEST COMMON PREFIX IN ARRAY OF STRINGS
*/

/*
	Approach 1 - Check Character-wise O(n^2)
*/

void cp()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    int min_len = INT_MAX;
    for(string &x : arr)
    {
        cin >> x;
        min_len = min(min_len, ln(x));
    }
    string ans;
    int ind = -1;
    for(int i = 0; i < min_len; i++)
    {
        set<char> s;
        for(int j = 0; j < n; j++)
        {
            s.insert(arr[j][i]);
        }
        if(sz(s) == 1)
            ind = i, ans += arr[0][i];
        else
            break;
    }
    if(sz(ans))
        cout << ans << endl;
    else
        cout << -1 << endl;
}
