/*
	Given List of balls on 2 roads in sorted order
	You can switch roads at places where there are same numbers in both roads, not necessarily on same indices
*/

/*
	Approach -
		Two Pointers
		We will traverse both roads keeping track of sum till we reach same numbers
		For traversal we can go about the technique used for merging sorted array

		Now if both numbers are same, we will add the maximum sum so far
		And reset the sums
		As the numbers further on could also be same, we can either traverse till the subarray same numbers end
		Or increment only one pointer and let rest of the code handle it

		At the end complete left over sums and add max

		O(n+m)
*/
void cp()
{
    clr(max_sum, 0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    ll ans = 0;
    ll suma = a[0], sumb = b[0];
    sort(all(a));
    sort(all(b));

    // Merging like
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            ans += max(suma, sumb);
            suma = 0, sumb = 0;
            // Increment only 1 pointer
            i++;
            if(i < n)
                suma += a[i];
        }
        else if(a[i] < b[j])
        {
            i++;
            if(i < n)
                suma += a[i];
        }
        else
        {
            j++;
            if(j < m)
                sumb += b[j];
        }
    }

    // Remaining
    while(i < n)
    {
        i++;
        if(i < n)
            suma += a[i];
    }
    while(j < m)
    {
        j++;
        if(j < m)
            sumb += b[j];
    }
    ans += max(suma, sumb);
    cout << ans << endl;
}
