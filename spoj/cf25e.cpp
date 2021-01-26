#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

vector<string> str(3);
vector<string> res;
vector<bool> mark(3);

string join(string &s, string &t)
{
    string p = t + "#" + s;
    // remove longest prefix of t that is suffix of s
    int n = ln(p);
    vector<int> longest_prefix(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && p[i] != p[k])
            k = longest_prefix[ k - 1];
        if(p[i] == p[k])
            longest_prefix[i] = ++k;
        else
            longest_prefix[i] = k;
    }
    int common = longest_prefix[n - 1];
    string res;
    for(int i = 0; i < ln(s); i++)
        res += s[i];
    for(int i = common; i < ln(t); i++)
        res += t[i];
    return res;
}

bool find_kmp(string &text, string &p)
{
    int n = ln(p);
    vector<int> longest_prefix(n);
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && p[i] != p[k])
            k = longest_prefix[k - 1];
        if(p[i] == p[k])
            longest_prefix[i] = ++k;
        else
            longest_prefix[i] = k;
    }
    n = ln(text);
    bool found = false;
    for(int i = 0, k = 0; i < n && !found; i++)
    {
        while(k > 0 && text[i] != p[k])
            k = longest_prefix[k - 1];
        if(p[k] == text[i])
            k++;
        if(k == ln(p))
            found = true;
    }
    return found;
}

void cp()
{
    fill(all(mark), false);
    res.clear();
    // check if one string is substring on another
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(i != j && !mark[i] && !mark[j])
                if(find_kmp(str[i], str[j]))
                    mark[j] = 1;

    for(int i = 0; i < 3; i++)
        if(!mark[i])
            res.pb(str[i]);

    int ans = INT_MAX;
    if(sz(res) == 1)
        ans = ln(res[0]);
    else if(sz(res) == 2)
        ans = min(ln(join(res[0], res[1])), ln(join(res[1], res[0])));
    else
    {
        vector<int> perm = {0, 1, 2};
        do
        {
            string x = join(str[perm[0]], str[perm[1]]);
            string y = join(x, str[perm[2]]);
            ans = min(ans, ln(y));
        }
        while(next_permutation(all(perm)));
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> str[0] >> str[1] >> str[2])
    {
        cp();
    }
    return 0;
}