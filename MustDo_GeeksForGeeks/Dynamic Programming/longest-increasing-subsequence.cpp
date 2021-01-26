/*
	Longest Increasing Subsequence
	Find length
*/

/*
	Approach 1 - DP O(n^2) time and space

		For every number it on its own is an LIS
		Also for every number we can attach it to the LIS of a number
		that occurs before this and which is smaller than this number
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int LIS[n];
    for(int i = 0; i < n; i++)
    {
        LIS[i] = 1; // it itself
        for(int j = 0; j < i; j++)
        {
        	// attach to previous smaller number
            if(arr[j] < arr[i])
                LIS[i] = max(LIS[i], LIS[j] + 1);
        }
    }
    cout << *max_element(LIS, LIS + n) << endl;
}
