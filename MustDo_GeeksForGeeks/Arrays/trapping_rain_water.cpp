/*
	TRAPPING RAIN WATER
	Given array of heights find how much total water is trapped between the structures

*/

/*
	Every structure will have >= 0 water on top of it. the amount of water is dependent
	on the maximum heights that lie on its left and right.
	Take the Smaller of those heights and the difference from this height is the water on top of this structure.

	APPROACH 1 - Find Left and Right Max for every height O(n^2) time O(1) space
	APPROACH 2 - Preprocess Left and Right Max for every height O(n) time O(n) space

*/

//APPROACH 1
ll arr[MAXN];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll water = 0;
    for(int i = 0; i < n; i++)
    {
        ll left = 0, right = 0;
        for(int j = i; j >= 0; j--)
            left = max(left, arr[j]);
        for(int j = i; j < n; j++)
            right = max(right, arr[j]);
        water += min(left, right) - arr[i];
    }
    cout << water << endl;
}

//APPROACH 2
int arr[MAXN], max_left[MAXN], max_right[MAXN];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max_left[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        max_left[i] = max(max_left[i - 1], arr[i]);
    }
    max_right[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        max_right[i] = max(max_right[i + 1], arr[i]);
    }
    ll water = 0;
    for(int i = 0; i < n; i++)
    {
        ll left = max_left[i], right = max_right[i];
        water += min(left, right) - arr[i];
    }
    cout << water << endl;
}