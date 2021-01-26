/*
	Sort Array A relative to Array B
*/
/*
	Approach 1 -
	First sort numbers in accordance to their index of presence in B
	Sort remaining numbers normally
*/
int freq[MAXN];
void cp()
{
    int n, m;
    cin >> n >> m;
    clr(freq, 0);
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x, freq[x]++;
    for(int &x : b)
        cin >> x;
    vector<int> rel, sorted;
    for(int x : b)
    {
        if(freq[x])
            for(int i = 0; i < freq[x]; i++)
                rel.pb(x);
        freq[x] = 0;
    }
    for(int i = 0; i < n; i++)
        if(freq[a[i]])
            sorted.pb(a[i]);
    sort(all(sorted));
    for(int x : rel)
        cout << x << " ";
    for(int x : sorted)
        cout << x << " ";
    cout << endl;
}
