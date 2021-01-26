/*
	Given Height of Piles of coins
	If difference in height of any 2 piles should be <= K
	|a-b| <= K
	We can only remove coins not add
	We can remove whole pile by removing all coins then that pile won't count anymore
*/

/*
	Approach - O(MAXH * n)
		We try to get all coins to Height [H H+k]

		If a pile is smaller we can remove this pile,
		If it is greater than H+k, remove the offset

		The minimum over all H is the answer
*/

const int MAXN = 1e3 + 5;

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    ll cnt = INT_MAX;
    for(int i = 0; i <= MAXN; i++)
    {
        ll del = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] < i)
                del += arr[j];
            else if(arr[j] - i > k)
            {
                int off = arr[j] - i - k;
                del += off;
            }
        }
        cnt = min(cnt, del);
    }
    cout << cnt << endl;
}
