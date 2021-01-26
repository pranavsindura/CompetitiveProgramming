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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

bool get(ll l, ll r)
{
    cout << l << " " << r << endl;
    cout.flush();
    string res;
    cin >> res;
    if(l == r && res == "Yes")
        exit(0);
    if(res == "Bad")
        exit(0);
    return (res == "Yes");
}

void cp()
{
    ll n, k;
    cin >> n >> k;
    ll ops = 0;
    ll lo = 1, hi = n;
    for(ops = 0; ops <= 4500; )
    {
        while(hi - lo > 6 * k)
        {
            ll mid = (lo + hi) / 2;
            if(get(lo, mid))
            {
                // is now in [lo-k, mid+k]
                lo = max(1LL, lo - k);
                hi = min(n, mid + k);
            }
            else
            {
                // is now is [mid+1-k, hi+k]
                lo = max(1LL, mid + 1 - k);
                hi = min(n, hi + k);
            }
            ops++;
        }
        ll len = hi - lo + 1;
        ll num = lo + rand() % len;
        get(num, num);
        ops++;
        lo = max(1LL, lo - k);
        hi = min(n, hi + k);
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    srand(time(NULL));
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}