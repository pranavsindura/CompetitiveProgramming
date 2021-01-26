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

ll path(ll u, ll v, ll w, map<pair<ll, ll>, ll> &val)
{
    map<pair<ll, ll>, bool> vis;
    ll total = 0;
    if(u > v)
        swap(u, v);
    while(u / 2)
    {
        ll par = u / 2;
        vis[mp(par, u)] = true;
        val[mp(par, u)] += w;
        total += val[mp(par, u)];
        u /= 2;
    }
    while(v / 2)
    {
        ll par = v / 2;
        if(vis.count({par, v}))
            val[mp(par, v)] -= w, total -= val[mp(par, v)];
        else
            val[mp(par, v)] += w, total += val[mp(par, v)];
        v /= 2;
    }
    return total;
}

void cp()
{
    int q;
    cin >> q;
    map<pair<ll, ll>, ll> val;
    while(q--)
    {
        int t;
        cin >> t;
        ll u, v, w;
        if(t == 1)
        {
            cin >> u >> v >> w;
            path(u, v, w, val);
        }
        else
        {
            cin >> u >> v;
            cout << path(u, v, 0, val) << endl;
        }
    }
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