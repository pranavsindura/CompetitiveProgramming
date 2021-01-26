/*
    CONVERT ARRAY TO A ZIG ZAG FASHION ARRAY
    a < b > c < d > e < f > g ....
*/

/*
    Approach 1 - Try all permutations O(n!)
    Approach 2 - Swap in-place O(n)
    if two elements are to be in ascending check if they are else swap
    else same for descending

*/

// Approach 2
void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    bool less = true;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            if(less)
            {
                //ok
            }
            else
                swap(arr[i], arr[i + 1]);
        }
        else
        {
            if(!less)
            {
                //ok
            }
            else
                swap(arr[i], arr[i + 1]);
        }
        less = !less;
    }
    for(int x : arr)
        cout << x << " ";
    cout << endl;
}
