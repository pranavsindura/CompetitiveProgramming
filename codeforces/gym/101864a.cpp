#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    ll x, l, n;
    cin >> x >> l >> n;
    ll safe = max(0LL, x - l);
    if(x & 1)
    {
        ll b = (x - 1) / 2;
        int cnt = 0;
        for(int i = 0; i < 60; i++)
        {
            if((b >> i) & 1)
                cnt = 0;
            else
            {
                ll num = b | (1LL << i);
                if(num <= n && num >= l)
                    cnt++;
            }
        }
        safe += cnt;
    }
    ll total = n - l + 1;
    ll g = gcd(safe, total);
    safe /= g, total /= g;
    cout << safe << "/" << total << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        cp();
    }
    return 0;
}