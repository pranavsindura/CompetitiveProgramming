/*
    LEFT SIDE SMALLER THAN RIGHT SIDE

    Given an unsorted array of size N. Find the first element in array such that all
    of its left elements are less than or equal to and all right elements to it are greater than or equal to it.
*/

/*
    Approach 1 - For every element check if it is answer O(n^2)
    Approach 2 - Prefix and Suffix arrays O(n)
    Hold maximum prefix and minimum suffix and check for each element if prefix <= arr[i] <= suffix
*/

const int MAXN = 1e6 + 5;
int arr[MAXN], pref_max[MAXN], suff_min[MAXN];
void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    pref_max[0] = arr[0];
    for(int i = 1; i < n; i++)
        pref_max[i] = max(pref_max[i - 1], arr[i]);
    suff_min[n] = INT_MAX;
    for(int i = n - 1; i >= 0; i--)
        suff_min[i] = min(suff_min[i + 1], arr[i]);

    int ans = -1;
    for(int i = 1; i < n - 1; i++)
    {
        if(pref_max[i - 1] <= arr[i] && arr[i] <= suff_min[i + 1])
        {
            ans = arr[i];
            break;
        }
    }
    cout << ans << endl;
}