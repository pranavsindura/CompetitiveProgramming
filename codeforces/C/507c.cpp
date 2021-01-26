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
    ll n, h;
    cin >> h >> n;
    bool left = true;
    ll lo = 1, hi = fpow(2, h);
    ll ans = 0;
    while(hi - lo + 1 > 1)
    {
        ll mid = (hi + lo) / 2;
        // cout << boolalpha << mid << " " << left << " " << ans << endl;
        if(n <= mid)
        {
            //go left
            if(left)
            {
                //ok
                left = !left;
            }
            else
            {
                ans += fpow(2, h) - 1;
            }
            hi = mid;
        }
        else
        {
            if(left)
            {
                ans += fpow(2, h) - 1;
            }
            else
            {
                //ok
                left = !left;
            }
            lo = mid + 1;
        }

        ans++;
        h--;
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