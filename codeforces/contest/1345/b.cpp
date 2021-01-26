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

ll calc(ll n)
{
    return (3LL * n * n + n) / 2;
}

void cp()
{
    ll n;
    cin >> n;
    bool possible = true;
    int count = 0;
    while(possible && n > 0)
    {
        possible = false;
        ll lo = 1, hi = 1e9;
        ll here = 0;
        while(lo <= hi)
        {

            ll mid = (lo + hi) / 2;
            // make mid height pyramid
            // cout << mid << " " << calc(mid) << " " << n << endl;
            if(calc(mid) <= n)
                lo = mid + 1, here = calc(mid), possible = true;
            else
                hi = mid - 1;
        }
        if(possible)
            count++, n -= here;
    }
    cout << count << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}