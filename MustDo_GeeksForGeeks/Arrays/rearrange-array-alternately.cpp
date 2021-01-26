/*
    RE-ARRANGE ARRAY ALTERNATELY in O(1) space

    max, min, max, min fashion
    1 2 3 4 5 6 -> 6 1 5 2 4 3
*/

/*
    Approach 1 - Picking min/max at every position O(n^2)
    if index is odd
        pick smallest number in remaining array and swap
    else
        pick largest numner in remaining array and swap
*/

/*
    Approach 2 - Storing two numbers at one position
    We can modify number to hold two numbers
    One as arr[i]%large_num and one as arr[i]/large_num

    We will let arr[i]%large_num represent orignal number and arr[i]/large_num represent new number

    we can have two pointers one for min_index and one for max_index
    if index is odd
        arr[i] := arr[i] + (arr[min_index]%large_num) * large_num, min_index := min_index-1
    else
        arr[i] := arr[i] + (arr[max_index]%large_num) * large_num, max_index := max_index+1

    arr[i] := arr[i] + (arr[min_index]%large_num) * large_num, min_index := min_index-1
    what this does is,
    arr[i] will become the remainder as it is not a multiple of large_num,
    and arr[min_index]%large_num will give us orignal number at min_index if it was changed(or not)

*/

//Apporach 2
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int min_index = 0, max_index = n - 1;
        ll mx = arr.back() + 1;
        for(int i = 0; i < n; i++)
        {
            if(i & 1)
                arr[i] = arr[i] + mx * (arr[min_index] % mx), min_index++;
            else
                arr[i] = arr[i] + mx * (arr[max_index] % mx), max_index--;
        }
        for(int i = 0; i < n; i++)
            arr[i] = arr[i] / mx;
        for(ll x : arr)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}