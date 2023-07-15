#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = (__int128)res * x % m;
        x = (__int128)x * x % m;
        y /= 2;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll m = a == b ? mod : a - b;
        ll x = (fpow(a, n, m) + fpow(b, n, m)) % m;
        ll y = a - b;
        // cout<<x<<" "<<y<<endl;
        cout << gcd(x, y) % mod << endl;
    }
    return 0;
}