/*
	LARGEST WINDOW WITH DISTINCT CHARACTERS ONLY
*/

/*
	Approach 1 - Try all Substrings O(n^3)
	Approach 2 - Sliding Window O(n)
*/

//Approach 2
void cp()
{
    string s;
    cin >> s;
    int i = 0, j = 0, n = ln(s);
    int cnt[26] = {0};
    cnt[s[0] - 'a']++;
    int mx = 1;
    while(j < n)
    {
        bool all_one = true;
        for(int k = 0; k < 26; k++)
        {
            if(cnt[k] > 1)
                all_one = false;
        }
        if(all_one)
        {
            mx = max(mx, j - i + 1);
            j++;
            if(j < n)
                cnt[s[j] - 'a']++;
        }
        else
        {
            if(i < j)
            {
                cnt[s[i] - 'a']--;
                i++;
            }
        }
    }
    cout << mx << endl;
}