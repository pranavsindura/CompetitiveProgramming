/*
	Smallest Window of a String containing All characters of another string
*/
/*
	Approach 1 - Check all Subarrays - O(n^3)
	Approach 2 - Check All subarrays + Prefix Sum for frequency count O(n^2)
	Approach 3 - Two pointer
		If current window has characters frequency less, increase right pointer
		Else increase left pointer
		Find smallest window
*/
void cp()
{
    string s, t;
    cin >> s >> t;
    int n = ln(s);
    int cnt_t[26] = {0};
    for(char x : t)
        cnt_t[x - 'a']++;
    int so_far[26] = {0};
    bool found = false;
    int st = -1, en = -1;
    int i = 0, j = 0;
    so_far[s[0] - 'a']++;
    while(j < n)
    {
        bool ok = true;
        for(int k = 0; k < 26; k++)
        {
            if(so_far[k] < cnt_t[k])
                ok = false;
        }
        if(ok)
        {
            //possible window
            if(found)
            {
                int len = j - i + 1;
                int best = en - st + 1;
                if(len < best)
                    st = i, en = j;
            }
            else
                st = i, en = j, found = true;
            if(i < j)
            {
                so_far[s[i] - 'a']--;
                i++;
            }
            else
            {
                j++;
                if(j < n)
                    so_far[s[j] - 'a']++;
            }
        }
        else
        {
            j++;
            if(j < n)
                so_far[s[j] - 'a']++;
        }
    }
    if(found)
        for(int i = st; i <= en; i++)
            cout << s[i];
    else
        cout << -1;
    cout << endl;
}
