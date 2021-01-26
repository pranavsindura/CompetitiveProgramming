/*
	Find first character that repeats in string S
*/

/*
	Approach 1 - Hashing/Frequency table
*/
void cp()
{
    string s;
    cin >> s;
    int cnt[26] = {0};
    bool found = false;
    char ans;
    for(char x : s)
    {
        if(cnt[x - 'a'])
        {
            found = true;
            ans = x;
            break;
        }
        else
            cnt[x - 'a']++;
    }
    if(found)
        cout << ans << endl;
    else
        cout << -1 << endl;
}