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
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

set<ll> store;
vector<ll> precomp;

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y /= 2;
    }
    return res;
}

void init()
{
    ll n = 1e18;
    for(int i = 1; i < sz(prime); i++)
    {
        ld res = powl((ld)n, 1.0 / prime[i]);
        ll upto = (ll)(res + eps);
        for(int j = 2; j <= upto; j++)
            store.insert(fpow(j, prime[i]));
    }

    for(ll x : store)
        precomp.pb(x);
    store.clear();
}

ll solve(ll n)
{
    if(n <= 1)
        return n;

    int ans = 0, lo = 0, hi = sz(precomp) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(precomp[mid] <= n)
            ans = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }

    ll sq = sqrt(n);
    int undersq = 0;
    lo = 0, hi = sz(precomp) - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(precomp[mid] <= sq)
            undersq = mid + 1, lo = mid + 1;
        else
            hi = mid - 1;
    }
    sq -= undersq;
    return ans + sq;
}

void cp()
{
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}