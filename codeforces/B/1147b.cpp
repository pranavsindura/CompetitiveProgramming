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

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> dist;
    for(int i = 0; i < m; i++)
    {
        int a, b, u, v, d;
        cin >> a >> b;
        u = max(a, b), v = min(a, b);
        d = u - v;
        if(d > n / 2)
            d = (-d + n) % n;
        dist[d].pb(u);
        dist[d].pb(v);
    }

    bool ok = true;
    ll x = 1;

    for(auto &it : dist)
    {
        sort(all(it.ss));
        // make an array for finding pattern
        vector<int> pat;
        for(int i = 0; i < sz(it.ss); i++)
            pat.pb((it.ss[(i + 1) % sz(it.ss)] - it.ss[i] + n) % n);

        vector<int> failure(sz(pat));
        for(int i = 1, k = 0; i < sz(pat); i++)
        {
            while(k && pat[i] != pat[k])
                k = failure[k - 1];
            if(pat[i] == pat[k])
                k++;
            failure[i] = k;
        }
        int rep = failure.back();
        if(rep && sz(pat) % (sz(pat) - rep) == 0)
        {
            int len = 0;
            rep = (sz(pat) - rep);
            for(int i = 0; i < rep; i++)
                len += pat[i];
            x = lcm(x, len);
        }
        else
            ok = false;

        if(!ok || x >= n)
            break;
    }

    if(ok && x < n)
        cout << "Yes\n";
    else
        cout << "No\n";
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