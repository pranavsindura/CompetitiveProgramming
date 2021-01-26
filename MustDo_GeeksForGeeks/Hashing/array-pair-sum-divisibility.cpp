/*
	Check if Array can be divided into pairs such that
	their sum is divisible by K
*/
/*
	Approach 1 - Pick 2 O(n^2)
	Approach 2 - See that if two numbers (a,b) form a pair
		(a+b)%k == 0
		(a%k + b%k)%k == 0
		a%k + b%k == k or 0

		so we can hash all of arr[i]%k
		and check for all modulo values
		i that k-i also exists and their frequencies are the same
		if i and k-i are equal their frequencies must be divisible by 2 to form a pair
*/

void cp()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    cin >> k;
    for(int &x : arr)
        x = x % k;
    bool ok = true;
    int freq[k];
    clr(freq, 0);
    for(int x : arr)
        freq[x]++;
    for(int i = 0; i <= k; i++)
    {
        int a = i % k, b = (k - i) % k;
        if((a == b && freq[a] % 2) || (freq[a] != freq[b]))
            ok = false;
    }
    cout << (ok ? "True" : "False") << endl;
}
