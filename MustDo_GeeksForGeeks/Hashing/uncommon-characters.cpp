/*
	Find Uncommon characters of String A and B
	Those characters which exist is A but not in B ans vice versa
*/
/*
	Approach 1 - Check for all alphabets by looping O(26*(n+m))
	Approach 2 - Hash both A and B and then check for all alphabets O(26)
*/
// Approach 2
void cp()
{
    string a, b;
    cin >> a >> b;
    int fa[26] = {0}, fb[26] = {0};
    for(char x : a)
        fa[x - 'a']++;
    for(char x : b)
        fb[x - 'a']++;
    for(char i = 'a'; i <= 'z'; i++)
    {
        if((fa[i - 'a'] && !fb[i - 'a']) || (!fa[i - 'a'] && fb[i - 'a']))
            cout << i;
    }
    cout << endl;
}