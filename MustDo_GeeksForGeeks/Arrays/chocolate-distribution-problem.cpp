/*
    CHOCOLATE DISTRIBUTION

    Distribute N packets (having Ai chocolates) among M people such that difference of maximum chocolates and minimum chocolates in minimum
*/

/*
    Approach 1 - Pick m from n and minimize O(nCm) -> O(n!)
    Approach 2 - Sort, pick m consecutive and minimize difference
*/


// Approach 2
ll arr[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int m;
    cin >> m;
    ll min_diff = LLONG_MAX;
    for(int i = m - 1; i < n; i++)
    {
        min_diff = min(min_diff, arr[i] - arr[i - m + 1]);
    }
    cout << min_diff << endl;
}