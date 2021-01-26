/*
	Minimize the Heights
	Given a list of heights of tower you can either subtract K from it or add K to it, only once
	and operation must be performed on all towers

	Find the minimum difference between highest and smallest tower after the operations
*/

/*
	Approach 1 - Try All operations on all towers O(2^n)

	Greedy
	Approach 2 -
		Sort the array now, you will want to add K to some prefix of the array
		And remove K from the remaining half of the elements
		Try all partitions
		O(n)

		Let's add K to all elements in range [0, i-1]
		and remove K from all elements in range [i, n-1]

		New maximum element => max( arr[n-1] - K, arr[i-1] + K )
		New minimum element => min( arr[i] - K, arr[0] + K )
*/

void cp()
{
    int n, k;
    cin >> k >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    if(n <= 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(arr));
    int ans = arr[n - 1] - arr[0];

    for(int i = 1; i < n; i++)
    {
        // add k to [0, i-1]
        // subtract k from [i, n-1]
        int mx = max(arr[i - 1] + k, arr[n - 1] - k);
        int mn = min(arr[0] + k, arr[i] - k);
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;
}
