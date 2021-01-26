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
string s;

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

void cp()
{
    string srev = s;
    reverse(all(srev));
    string t = srev + "#" + s;
    // cout << t << ": ";
    vector<int> longest_prefix = compute_prefix(t);
    int max_match = longest_prefix.back();
    // cout << max_match << endl;
    string ans = s;
    for(int i = max_match; i < ln(srev); i++)
        ans += srev[i];
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> s)
    {
        cp();
    }
    return 0;
}