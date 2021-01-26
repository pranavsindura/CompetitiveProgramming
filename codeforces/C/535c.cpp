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

ll A, B;

ll f(ll n)
{
    return n * (2 * A + (n - 1) * B) / 2;
}

void cp()
{
    int q;
    cin >> A >> B >> q;
    while(q--)
    {
        ll l, t, m;
        cin >> l >> t >> m;
        ll ans = -1;
        ll lo = 0, hi = 1e9;
        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll sum = f(l + mid) - f(l - 1);
            ll group = min(m, mid + 1);
            ll op = (sum + group - 1) / group;
            op = max(op, A + (l + mid - 1) * B);
            if(op <= t)
                ans = l + mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout << ans << endl;
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