/*
	Print permutations of string
*/

/*
	Approach 1 - Use Recursion
	Approach 2 - Use next_permutation
*/

//Approach 1
vector<string> res;
bool mark[6];

void rec(string &s, string ans)
{
    bool done = true;
    for(int i = 0; i < ln(s); i++)
    {
        if(!mark[i])
        {
            mark[i] = true;
            ans += s[i];
            rec(s, ans);
            ans.pop_back();
            mark[i] = false;
            done = false;
        }
    }
    if(done)
        res.pb(ans);
}

void cp()
{
    string s;
    cin >> s;
    res.clear();
    rec(s, "");
    sort(all(res));
    for(string x : res)
        cout << x << " ";
    cout << endl;
}

//Approach 2
void cp()
{
    string s;
    cin >> s;
    sort(all(s));
    do
    {
        cout << s << " ";
    }
    while(next_permutation(all(s)));
    cout << endl;
}