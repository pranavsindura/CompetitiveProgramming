/*
	First Element to Occur K times in an array
*/
/*
	Approach 1 - 	Find Frequency of each numbers
					Loop again to find the first number with frequency = K
*/
void cp()
{
    unordered_map<int, int> freq;
    int n, k;
    cin >> n >> k;
    int ans = -1;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(freq[arr[i]] == k)
        {
            ans = arr[i];
            break;
        }
    }
    cout << ans << endl;
}
