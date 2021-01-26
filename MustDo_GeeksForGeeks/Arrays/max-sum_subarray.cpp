/*
    MAXIMUM SUM SUBARRAY
*/
/*
    Approach 1 - Brute Force O(n^3)
    Go over all sub arrays and find sum, maximize

    Approach 2 - Brute force with prefix O(n^2)
    Go over all sub arrays and find sum with prefix, maximize

    Approach 3 - Divide and Conquer O(nlogn)
    Break subarray into two halves left and right
    Maxsubarray is maximum of -
    1. Maxsubarray in left half,
    2. Maxsubarray in right half
    3. MaxCrossSum i.e. max suffix of left half + max prefix of right half

    Approach 4 - DP/Kadane's algorithm O(n), can be done in constant space as well, only need previous and overall maximum
    dp[i] = maxsubarray ending at i
    Transition
    dp[i] = max(dp[i-1] + arr[i], arr[i])
    Maxsubarray ending at i, we can either concatenate arr[i] and previous subarray or make it an independent subarray itself

    Maximum subarray will be maximum in all of dp from 1 to n
*/

//Approach 3
ll arr[MAXN];

ll max_sum(int l, int r)
{
    if(l > r)
        return 0;
    if(l == r)
        return arr[l];

    int m = (l + r) / 2;
    ll left = max_sum(l, m);
    ll right = max_sum(m + 1, r);
    ll max_suffix_left = INT_MIN, max_prefix_right = INT_MIN, suffix_left = 0, prefix_right = 0;
    for(int i = m; i >= l; i--)
    {
        suffix_left += arr[i];
        max_suffix_left = max(max_suffix_left, suffix_left);
    }
    for(int i = m + 1; i <= r; i++)
    {
        prefix_right += arr[i];
        max_prefix_right = max(max_prefix_right, prefix_right);
    }
    return max({left, right, max_suffix_left + max_prefix_right});
}

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << max_sum(0, n - 1) << endl;
}

//Approach 4
ll arr[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    ll sum = arr[0];
    ll dp[n + 1];
    dp[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
    cout << *max_element(dp, dp + n) << endl;
}