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
const int MAXN = 1e5 + 5;

vector<int> parity[2];

void init()
{
    for(int i = 1; i < MAXN; i++)
    {
        ll n = i * 1LL * (i + 1) / 2;
        parity[n & 1].pb(i);
    }
}

void cp()
{
    ll f;
    cin >> f;
    f = abs(f);
    int lo = 0, hi = sz(parity[f & 1]);
    int ans = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        ll val = parity[f & 1][mid] * 1LL * (parity[f & 1][mid] + 1) / 2;
        if(val >= f)
            ans = parity[f & 1][mid], hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
        if(t)
            cout << endl;
    }
    return 0;
}
