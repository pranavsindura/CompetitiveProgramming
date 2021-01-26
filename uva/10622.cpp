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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 100005;

vector<ll> div(ll x)
{
    map<ll, int> f;
    while(x % 2 == 0)
        f[2]++, x /= 2;
    for(ll i = 3; i <= sqrt(x); i += 2)
    {
        while(x % i == 0)
            f[i]++, x /= i;
    }
    if(x > 1)
        f[x]++;
    vector<ll> v;
    for(auto a : f)
        v.pb(a.ss);
    return v;
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    ll n;
    cin >> n;
    while(n)
    {
        ll temp = abs(n);
        vector<ll> v = div(temp);
        ll p = v[0];
        for(int i = 1; i < sz(v); i++)
            p = gcd(p, v[i]);
        if(n < 0)
        {
            while(p % 2 == 0)
                p /= 2;
        }

        cout << p << endl;
        cin >> n;
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