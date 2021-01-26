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
    string recipe;
    cin >> recipe;
    ll req_b = 0, req_s = 0, req_c = 0;
    for(char x : recipe)
        if(x == 'B')
            req_b++;
        else if(x == 'S')
            req_s++;
        else
            req_c++;
    ll have_b, have_s, have_c, price_b, price_s, price_c, money;
    cin >> have_b >> have_s >> have_c >> price_b >> price_s >> price_c >> money;

    ll lo = 0, hi = LLONG_MAX;
    if(req_b)
        hi = min(hi, money + have_b / req_b);
    if(req_s)
        hi = min(hi, money + have_s / req_s);
    if(req_c)
        hi = min(hi, money + have_s / req_c);
    ll ans = 0;
    while(lo <= hi)
    {
        // make mid burgers
        ll mid = (lo + hi) / 2;
        ll need_b = max(0LL, req_b * mid - have_b);
        ll need_s = max(0LL, req_s * mid - have_s);
        ll need_c = max(0LL, req_c * mid - have_c);
        // buy ingredients
        ll cost = need_b * price_b + need_s * price_s + need_c * price_c;
        if(cost <= money)
        {
            // make!
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
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