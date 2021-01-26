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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll p = -1, q = -1;
    ll lo = 1, hi = 1e9;
    while(lo <= hi)
    {
        // buy from a, single
        ll mid = (lo + hi) / 2;
        ll cost_a = mid * a;
        ll cost_b = (mid + b - 1) / b * c;
        if(cost_a < cost_b)
        {
            p = mid;
            break;
        }
        else
            hi = mid - 1;
    }
    lo = 1, hi = 1e9;
    while(lo <= hi)
    {
        //buy from b, multiples
        ll mid = (lo + hi) / 2;
        ll cost_a = mid * a * b;
        ll cost_b = mid * c;
        if(cost_a > cost_b)
        {
            q = mid;
            break;
        }
        else
            hi = mid - 1;
    }
    cout << p << " " << q << endl;
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