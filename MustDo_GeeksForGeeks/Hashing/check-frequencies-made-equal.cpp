/*
	Check if by removing at most 1 character can the frequencies of all distinct characters be made equal
*/
/*
	Approach 1 - 	Remove every character and test if frequencies are equal
					Also check by removing 0 characters
					O(n^2)
	Approach 2 - 	We can only satisfy constraint if -
					1. max frequency and min frequency are same
					2. difference between max and min freq is 1
						And either the max frequency occurs once (downsize frequency)
						or the min frequency occurs once (upsize frequency)
					O(n)
*/

// Approach 2
void cp()
{
    string s;
    cin >> s;
    int cnt[26] = {0};
    for(char x : s)
        cnt[x - 'a']++;
    int mx = INT_MIN;
    int mx_cnt = 0, mn_cnt = 0;
    int mn = INT_MAX;
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] > 0)
            mn = min(mn, cnt[i]), mx = max(mx, cnt[i]);
    }
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] == mx)
            mx_cnt++;
        if(cnt[i] == mn)
            mn_cnt++;
    }
    bool ok = false;
    if(mx == mn || (mx - mn == 1 && (mx_cnt <= 1 || mn_cnt <= 1)))
        ok = true;
    cout << ok << endl;
}
