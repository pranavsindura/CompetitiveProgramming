/*
	Longest Consecutive Subsequence

	Basically what is the largest subsequence when sorted gives most consecutive numbers
	OR
	Largest length of consecutive numbers when sorted
*/
/*
	Approach 1 - Sorting and check is prev is equal to curr-1 and increasing length
			O(nlogn) time
	Approach 2 - Hash and check with Two pointers for largest consecutive subarray in frequency array
			O(n) time
*/
// Approach 1
void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    // Remove Duplicates
    set<int> s(all(arr));
    arr = vector<int>(all(s));
    int cnt = 1;
    int mx = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i - 1] + 1)
            cnt++;
        else
            cnt = 1;
        mx = max(mx, cnt);
    }
    cout << mx << endl;
}


// Approach 2
void cp()
{
    bool exist[MAXN] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        exist[x] = true;
    }
    int mx = 0, l = 0, r = 0;
    int cnt = 0;
    while(r < MAXN)
    {
        if(exist[r])
            cnt++;
        else
            cnt = 0, l = r + 1;
        mx = max(mx, cnt);
        r++;
    }
    cout << mx << endl;
}
