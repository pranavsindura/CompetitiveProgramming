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

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if((2 * n * m) % k)
    {
        cout << "NO\n";
        return;
    }

    if(k & 1)
    {
        ll g = k;
        ll g1 = gcd(g, n), g2 = g / g1;
        ll ndash = n / g1;
        ll mdash = m / g2;
        if(2 * ndash <= n && mdash <= m)
        {
            cout << "YES\n";
            cout << 0 << " " << 0 << endl;
            cout << 2 * ndash << " " << 0 << endl;
            cout << 0 << " " << mdash << endl;
        }
        else if(ndash <= n && 2 * mdash <= m)
        {
            cout << "YES\n";
            cout << 0 << " " << 0 << endl;
            cout << ndash << " " << 0 << endl;
            cout << 0 << " " << 2 * mdash << endl;
        }
        else
            cout << "NO\n";
    }
    else
    {
        k /= 2;
        ll g = k;
        ll g1 = gcd(g, n), g2 = g / g1;
        n /= g1, m /= g2;
        cout << "YES\n";
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
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