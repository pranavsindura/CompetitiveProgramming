/*
    REVERSE WORDS IN A STRING

    Break open words and then reverse them and output
*/

void cp()
{
    string s;
    cin >> s;
    vector<string> words;
    string temp;
    for(int i = 0; i < ln(s); i++)
    {
        if(s[i] == '.')
            words.pb(temp), temp = "";
        else
            temp += s[i];
    }
    if(ln(temp))
        words.pb(temp);
    reverse(all(words));
    for(int i = 0; i < sz(words); i++)
    {
        if(i)
            cout << '.' << words[i];
        else
            cout << words[i];
    }
    cout << endl;
}
