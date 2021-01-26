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
    ll n;
    cin >> n;
    vector<int> fac;
    if(n % 2 == 0)
    {
        int cnt = 0;
        while(n % 2 == 0)
            cnt++, n = n / 2;
        fac.pb(cnt);
    }
    for(ll i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
                cnt++, n /= i;
            fac.pb(cnt);
        }
    }
    if(n > 1)
        fac.pb(1);
    ll ans = 0;
    for(int x: fac)
    {
    	int res = (-1 + (int)sqrt(1+8*x))/2;
    	ans += res;
    }
    cout << ans;
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