/*
	Check if two arrays are equal
*/
/*
	Approach 1 - Sorting and checking O(nlogn)

	Approach 2 - Hashing and checking if same frequency exists or not O(n) time assuming unordered_map takes O(1) time on average
*/

// Approach 1
void cp()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;
    sort(all(a));
    sort(all(b));
    cout << (a == b) << endl;
}


// Approach 2
void cp()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a)
        cin >> x;
    unordered_map<ll, int> cnt;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    bool ok = true;
    for(ll x : a)
    {
        if(cnt[x])
            cnt[x]--;
        else
            ok = false;
    }
    cout << ok << endl;
}