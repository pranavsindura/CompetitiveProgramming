#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 3000 + 5;
ll C[MAXN][MAXN];

void init()
{
    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
}

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y = y / 2;
    }
    return res;
}

void cp()
{
    int n, k, garb;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
        cin >> garb;
    ll ans = 0;
    // Inclusion Exclusion
    for(int i = 0; i < k; i++)
    {
        ll sg = (i % 2 == 0 ? +1 : -1);
        ans = (ans + ((sg * (k - i) * fpow(k - i - 1, n - 1)) % mod * C[k][i]) % mod + mod) % mod;
    }
    cout << ans;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}