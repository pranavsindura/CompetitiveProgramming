/*
	Remove Duplicates from string.
	May contains spaces 
*/
/*
	Approach 1 - Hashing O(n) time O(256) space
*/
void cp()
{
    string s;
    getline(cin, s);
    int freq[256] = {0};
    string ans;
    for(int i=0;s[i] != '\0';i++)
    {
        char x = s[i];
        if(freq[int(x)] == 0)
            ans += x, freq[int(x)]++;
    }
    cout<<ans<<endl;
}