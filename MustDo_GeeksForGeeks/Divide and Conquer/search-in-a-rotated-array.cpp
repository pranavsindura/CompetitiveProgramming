/*
	Search in a Rotated Array
*/

/*
	Approach 1 - O(n + logn)
		Find pivot point
		Binary search individually each half

	Approach 2 - O(logn)
		Modify Binary search to handle wrap arounds
*/


// Approach 1
int arr[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    int shift = 0;
    // max element / the rotated end is at positon shift
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > arr[(i + 1) % n])
            shift = i;
    }
    int pos = -1;
    int lo = 0, hi = shift;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(arr[mid] > k)
            hi = mid - 1;
        else if(arr[mid] < k)
            lo = mid + 1;
        else
        {
            pos = mid;
            break;
        }
    }
    lo = shift + 1, hi = n - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(arr[mid] > k)
            hi = mid - 1;
        else if(arr[mid] < k)
            lo = mid + 1;
        else
        {
            pos = mid;
            break;
        }
    }
    cout << pos << endl;
}