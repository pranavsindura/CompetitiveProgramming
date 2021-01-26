/*
	Candy shop

	For every 1 candy you buy, you get K candies free

	Find min cost of buying N candies
	Find max cost of buying N candies
*/
/*
	Approach 1 -
		First find the number of single candies you'd need to buy
		For every 1 candy you get K free, so loop and find the smallest x such that,
		x + k * x >= N

		After that sort the array and pick first x for min cost
		Pick last x for max cost
*/
void cp()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));
    int mn = 0, mx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i + k * i < n)
            continue;
        else
        {
            for(int j = 0; j < i; j++)
                mn += arr[j];
            reverse(all(arr));
            for(int j = 0; j < i; j++)
                mx += arr[j];
            break;
        }
    }
    cout << mn << " " << mx << endl;
}