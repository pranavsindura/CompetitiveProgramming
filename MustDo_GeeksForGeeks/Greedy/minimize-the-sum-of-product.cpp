/*
	Given 2 arrays A and B, Minimize the Sum or Products
	A[0]*B[0] + A[1]*B[1] + .... + A[N-1]*B[N-1]
*/

/*
	Approach 1 -
		Sort one array in ascending order and one in descending order
*/
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
    sort(allr(b));
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i] * b[i];
    cout << ans << endl;
}