
// Compute longest prefix array
vector<int> compute_prefix(string &p)
{
    int n = ln(p);
    vector<int> longest_prefix(n);
    // p[0] = 0
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && p[i] != p[k])
            k = longest_prefix[k - 1];

        if(p[i] == p[k])
            longest_prefix[i] = ++k;
        else
            longest_prefix[i] = k;
    }
    return longest_prefix;
}

// KMP Matching with another string
void kmp(string &text, string &pat)
{
    vector<int> longest_prefix = compute_prefix(pat);

    int n = ln(text), m = ln(pat);

    for(int i = 0, k = 0; i < n; i++)
    {
        while(k > 0 && text[i] != pat[k])
            k = longest_prefix[k - 1];
        if(text[i] == pat[k])
            k++;
        if(k == m)
        {
            cout << i - m + 1 << endl;
            k = longest_prefix[k - 1];
        }
    }
}