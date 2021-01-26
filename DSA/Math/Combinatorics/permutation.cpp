// Count all permutations of string A strictly less than string B
ll perm(string &a, string &b)
{
    int n = ln(a);

    vector<int> freq(26, 0);
    for(char x : a)
        freq[x - 'a']++;

    ll perm = fact[n];
    for(int x : freq)
        perm = (perm * invfact[x]) % mod;

    int len = n;
    ll up = 0;
    for(int i = 0; i < n; i++)
    {
        // less at i, equal before
        for(char c = 'a'; c < b[i]; c++)
        {
            if(freq[c - 'a'] == 0) continue;
            ll nperm = (perm * fact[freq[c - 'a']]) % mod;
            nperm = (nperm * invfact[freq[c - 'a'] - 1]) % mod;
            nperm = (nperm * invfact[len]) % mod;
            nperm = (nperm * fact[len - 1]) % mod;
            up = (up + nperm) % mod;
        }
        if(freq[b[i] - 'a'] == 0) break;
        ll nperm = (perm * fact[freq[b[i] - 'a']]) % mod;
        nperm = (nperm * invfact[freq[b[i] - 'a'] - 1]) % mod;
        nperm = (nperm * invfact[len]) % mod;
        nperm = (nperm * fact[len - 1]) % mod;
        perm = nperm;
        freq[b[i] - 'a']--;
        len--;
    }
    return up;
}

/*
Generate the xth permutation
Refer UVA 153

Write down here later
*/