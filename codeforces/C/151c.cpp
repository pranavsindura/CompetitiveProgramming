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

void cp()
{
    ll n, temp;
    cin >> n;
    temp = n;
    // map<ll, int> f;
    vector<ll> fac;
    while(n % 2 == 0)
        n /= 2, fac.pb(2);
    for(ll i = 3; i <= sqrt(n); i += 2)
    {
        while(n % i == 0)
            n /= i, fac.pb(i);
    }
    if(n > 1)
        fac.pb(n);
    if(sz(fac) > 1)
    {
        ll num = fac[0] * fac[1];
        n = temp;
        if(num == n)
            cout << 2;
        else
            cout << 1 << endl << num;
    }
    else
        cout << "1\n0";
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