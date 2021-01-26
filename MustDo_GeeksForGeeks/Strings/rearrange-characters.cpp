/*
	Rearrange Characters such that two two adjacent are same
	Check if possible
*/
/*
	Approach 1 -
		Any characters appearing > (length+1)/2 times will make it impossible for arrangement
*/
void cp()
{
    string s;
    cin >> s;
    int cnt[26] = {0};
    for(char x : s)
        cnt[x - 'a']++;
    int n = ln(s);
    bool ok = true;
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] > (n + 1) / 2)
            ok = false;
    }
    cout << ok << endl;
}