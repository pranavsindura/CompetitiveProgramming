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

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % mod * x % mod) % mod;
        x = (x % mod * x % mod) % mod;
        y >>= 1;
    }
    return res;
}

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> left, right;
    for(char x : s)
        right[x]++;

    ll ans = 0;
    for(char x : s)
    {
        right[x]--;
        if(x == 'b' || x == '?')
        {
            ll p = left['a'] * fpow(3, left['?']) + left['?'] * fpow(3, left['?'] - 1);
            p %= mod;
            ll q = right['c'] * fpow(3, right['?']) + right['?'] * fpow(3, right['?'] - 1);
            q %= mod;
            ans = (ans + p * q) % mod;
        }
        left[x]++;
    }
    cout << ans << endl;
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