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
const ll mod = 1e9 + 9;
const int MAXN = 1e6 + 5;

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
    return res % mod;
}
void cp()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll mul = n / k;
    ll rem = n % k;

    ll score = 0;
    if(m <= rem)
    {
        score += m, m = 0;
        cout << score % mod;
        return;
    }
    else
        score += rem, m -= rem;

    if(m <= (k - 1) * mul)
    {
        score += m, m = 0;
        cout << score % mod;
        return;
    }
    else
        score += (k - 1) * mul, m -= (k - 1) * mul;
    ll func = (fpow(2, m) - 1 + mod) % mod;
    func = (func % mod * k % mod) % mod;
    func = (func % mod * 2) % mod;
    score = (score % mod + func % mod) % mod;
    score = (score % mod - m * (k - 1) + mod) % mod;
    cout << score;
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