/*
	Find the character in String B which has smallest index in string A
*/

/*
	Approach - 	Make list of all chars that exist in B, O(n)
				Loop on A to see if char exists in B, if it does then it is minimum index char
*/
void cp()
{
    string s, p;
    cin >> s >> p;
    bool present[26] = {0};
    for(char x : p)
        present[x - 'a'] = true;
    char ans = '$';
    for(char x : s)
    {
        if(present[x - 'a'])
        {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
}