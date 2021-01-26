/*
	Sort elements by frequency
	Higher frequency comes first
	If two numbers have same frequency smaller number comes first
*/
/*
	Approach 1 - Hashing, Sorting by freq
*/
void cp()
{
    int n;
    cin >> n;
    int freq[61] = {0};
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> sorted_by_freq(60);
    iota(all(sorted_by_freq), 1);
    sort(all(sorted_by_freq), [&](int a, int b)
    {
        return (freq[a] == freq[b] ? (a < b) : (freq[a] > freq[b]));
    });
    for(int i = 0; i < sz(sorted_by_freq); i++)
    {
        for(int j = 0; j < freq[sorted_by_freq[i]]; j++)
            cout << sorted_by_freq[i] << " ";
    }
    cout << endl;
}