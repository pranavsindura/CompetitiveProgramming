/*
	RECURSIVELY REMOVE ALL ADJACENT CHARACTERS
	acaaabbbacdddd -> acac
*/
/*
	Approach 1 -
	To to remove adjacent characters use sliding window,
	find substring of max length of same characters
	If length > 1 that means there are adjacent characters, dont add to new string
	else add char to new string

	recursively perform this on new string while operations are being done

	Approach 2 -
	Use stack to remove adjacent characters!
*/

string rec(string s)
{
    string temp;
    bool any = false;
    int n = ln(s);
    int i = 0, j = 0;
    while(j < n)
    {
        while(j + 1 < n && s[j + 1] == s[i])
            j++;
        if(j - i + 1 > 1)
        {
            //pass
            any = true;
        }
        else
            temp += s[j];
        i = j + 1;
        j++;
    }
    if(!any)
        return temp;
    else
        return rec(temp);
}

void cp()
{
    string s;
    cin >> s;
    cout << rec(s) << endl;
}