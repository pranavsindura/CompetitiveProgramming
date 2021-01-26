#include<bits/stdc++.h>
#define ll long long int
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
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
    ll a, b, x, y;
    ll max_area = 0;
    ll p, q;
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g, y /= g;
    if(x > a || y > b)
    {
        cout << "0 0";
        return;
    }
    p = x, q = y;
    ll lo = 0, hi = 1e9;
    ll mul = 0;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if(p + x * mid <= a && q + y * mid <= b)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    // while(p + x <= a && q + y <= b)
    // {
    //     p += x, q += y;
    // }
    cout << p + (lo - 1) * x << " " << q + (lo - 1) * y;
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