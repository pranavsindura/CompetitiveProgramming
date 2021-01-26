/*
	Every element occurs Twice except one in sorted array
	Find which one
*/
/*
	Approach 1 - Array is sorted, check every adjacent number O(n)
	Approach 2 - Standard XOR problem, XOR all numbers, the xor value at end is the number we need O(n)
	Approach 3 - Binary Search O(logn)
		Notice that initially All numbers at even indices share the same number with their next positon
		Then after some position, because of a single number
		Now even indices share the same number with their previous one
		We can binary search this point
*/

// Approach 3
const int MAXN = 1e6 + 5;
ll arr[MAXN];
void cp()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int lo = 0, hi = n - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(mid % 2)
        {
            // if it shares number with mid-1 then we are in left half of the number
            // else we are in the right half
            if(arr[mid] == arr[mid - 1]) // need not check mid-1>=0 as first odd number is 1
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        else
        {
            // if it shares number with mid+1 then we are in left half of the number
            // else we are in the right half
            if(mid+1<n && arr[mid] == arr[mid + 1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    cout << arr[lo] << endl;
}

// Approach 2
void cp()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
}
