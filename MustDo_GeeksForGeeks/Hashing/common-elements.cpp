/*
	Given 3 Arrays, print their common elements
*/
/*
	Approach 1 - Hashing and Looping
*/
int a[MAXN], b[MAXN], c[MAXN];
void cp()
{
    int na, nb, nc;
    cin >> na >> nb >> nc;
    map<ll, int> fa, fb, fc;
    for(int i = 0; i < na; i++)
        cin >> a[i], fa[a[i]]++;
    for(int i = 0; i < nb; i++)
        cin >> b[i], fb[b[i]]++;
    for(int i = 0; i < nc; i++)
        cin >> c[i], fc[c[i]]++;
    vector<ll> common;
    for(auto &num : fa)
    {
        if(fb[num.ff] && fc[num.ff])
            common.pb(num.ff);
    }
    if(common.empty())
        cout << -1;
    else
        for(ll x : common)
            cout << x << " ";
    cout << endl;
}