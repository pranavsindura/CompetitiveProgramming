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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ab, ba;
    
    int cnt[2] = {0};
    for(int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']++;
        if(s[i] == t[i])
            continue;
        if(s[i] == 'a')
            ab.pb(i);
        else
            ba.pb(i);
    }

    bool ok = true;
    vector<vector<int>> ops;

    if(cnt[0] % 2 || cnt[1] % 2)
        ok = false;
    else
    {
        if(sz(ab) % 2 && sz(ba) % 2)
        {
            ops.pb({ba.back(), ba.back()});
            ab.pb(ba.back());
            ba.pop_back();
        }

        for(int i = 0; i + 1 < sz(ab); i += 2)
            ops.pb({ab[i], ab[i + 1]});
        for(int i = 0; i + 1 < sz(ba); i += 2)
            ops.pb({ba[i], ba[i + 1]});
    }

    if(ok)
    {
        cout << sz(ops) << endl;
        for(auto v : ops)
            cout << v[0] + 1 << " " << v[1] + 1 << endl;
    }
    else
        cout << -1 << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}