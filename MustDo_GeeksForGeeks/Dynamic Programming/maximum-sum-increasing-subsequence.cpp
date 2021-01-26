/*
	Maximum sum Increasing subsequence
*/

/*
	Approach 1 - Modification on LIS O(n^2)
		Instead of length we manage sum

	Approach 2 - BIT/ST + Array compression O(nlogn)
		I'll come back to this solution later
*/

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll LIS[n];
    for(int i = 0; i < n; i++)
    {
        LIS[i] = arr[i]; // it itself
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
                LIS[i] = max(LIS[i], LIS[j] + arr[i]);
        }
    }
    cout << *max_element(LIS, LIS + n) << endl;
}