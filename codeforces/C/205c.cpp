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

ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}


void cp()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0;

    auto check = [&](ll n)
    {
        return n >= l && n <= r;
    };

    for(int d = 1; d <= 9; d++)
    {
        if(check(d))
            ans++;

        if(check(d * 10 + d))
            ans++;

        for(int b = 1; b <= 16; b++)
        {
            ll lo = 0, hi = fpow(10, b) - 1;
            ll found_l = 0;

            while(lo <= hi)
            {
                ll mid = lo + (hi - lo) / 2;
                ll n = d * fpow(10, b) + mid;
                n = n * 10 + d;

                if(n >= l)
                    found_l = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }

            lo = 0, hi = fpow(10, b) - 1;
            ll found_r = hi;
            while(lo <= hi)
            {
                ll mid = lo + (hi - lo) / 2;
                ll n = d * fpow(10, b) + mid;
                n = n * 10 + d;

                if(n <= r)
                    found_r = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }

            ll num_l = (d * fpow(10, b) + found_l) * 10 + d;
            ll num_r = (d * fpow(10, b) + found_r) * 10 + d;

            if(check(num_l) && check(num_r) && num_l <= num_r)
                ans += found_r - found_l + 1;
        }
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