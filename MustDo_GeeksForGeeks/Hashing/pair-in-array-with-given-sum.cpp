/*
	Given two unsorted arrays A of size N and B of size M of distinct elements,
	the task is to find all pairs from both arrays whose sum is equal to X
*/
/*
	Approach 1 - Brute Force O(n*m)
	Approach 2 - Binary search O((n+m)logn)
*/

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x;
    sort(all(a));
    for(int &x : b)
        cin >> x;
    vector<pi> ans;
    for(int x : b)
    {
        // a + b = k => a = k - b
        int need = k - x;
        if(binary_search(all(a), need))
        {
            ans.push_back({need, x});
        }
    }
    if(ans.empty())
        cout << -1;
    else
    {
        sort(all(ans));
        for(int i = 0; i < sz(ans); i++)
        {
            if(i)
                cout << ", " << ans[i].ff << " " << ans[i].ss;
            else
                cout << ans[i].ff << " " << ans[i].ss;
        }
    }
    cout << endl;
}
