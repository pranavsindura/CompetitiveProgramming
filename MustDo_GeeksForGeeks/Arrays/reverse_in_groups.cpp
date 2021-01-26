/*
    REVERSE ARRAY IN GROUPS
*/

/*
    APPROACH 1 - O(n) time O(n) space
    Reverse multiples of group first then remainder and store in new array

    APPROACH 2 - O(n) time O(1) space
    Reverse multiples of group first then remainder inplace
*/

ll arr[MAXN];
void cp()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < (n / k)*k; i += k)
    {
        for(int j = 0; j < k / 2; j++)
        {
            swap(arr[i + j], arr[i + (k - j - 1)]);
        }
    }
    int last_ind = (n / k) * k;
    int rem = n - last_ind;
    for(int i = 0; i < rem / 2; i++)
    {
        swap(arr[last_ind + i], arr[last_ind + (rem - i - 1)]);
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}