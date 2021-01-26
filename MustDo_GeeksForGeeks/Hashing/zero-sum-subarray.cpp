/*
	Count Subarray with ZERO sum
*/
/*
	Approach 1 - Check all Subarrays O(n^3)
	Approach 2 - Check all Subarrays with prefix O(n^2)
	Approach 3 - Use map to see if current sum has been seen before O(n) assuming unordered_map gives O(1) complexity on average
		Similar to count subarrays with given sum
*/

// Approach 3
void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll sum = 0;
    unordered_map<ll, int> seen_sum;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
            cnt++;
        if(seen_sum.find(sum) != end(seen_sum))
            cnt += seen_sum[sum];
        seen_sum[sum]++;
    }
    cout << cnt << endl;
}