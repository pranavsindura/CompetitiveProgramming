/*
	Check if Array B is a subuset of array A
*/
/*
	NO need for checkign relative position
	Just check if it exists
	Approach 1 - Check if each element of B exists in A, Brute Force O(n*m)
	Approach 2 - Hash elements of A and just check if element exists while traversing B O(n+m)
*/
// Approach 2
void cp()
{
    int n, m;
    cin >> n >> m;
    int pos[MAXN];
    clr(pos, -1);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    vector<int> b(m);
    bool ok = true;
    for(int &x : b)
        cin >> x;
    for(int x : b)
    {
        if(pos[x] == -1)
            ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
}
