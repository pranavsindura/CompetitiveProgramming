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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;

    map<int, vector<int>> range;
    vector<pair<int, ll>> end_val;

    auto sum = [&](int l)
    {
        ll res = end_val.back().ss - (l ? end_val[l - 1].ss : 0);
        res = (res + mod) % mod;
        return res;
    };

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        range[b].pb(a);
    }

    end_val.pb({0, 1});

    for(auto &p : range)
    {
        ll total = 0;
        for(int start : p.ss)
        {
            int ind = lower_bound(all(end_val), mp(start, 0LL)) - begin(end_val);
            if(ind < sz(end_val))
                total = (total +  sum(ind)) % mod;
        }
        end_val.pb({p.ff, (total + end_val.back().ss) % mod});
    }

    int last = end_val.back().ff;
    ll val = sum(sz(end_val) - 1);
    
    cout << (last == n ? val : 0);
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