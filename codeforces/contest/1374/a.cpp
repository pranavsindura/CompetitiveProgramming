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

void cp()
{
    ll x, y, n;
    cin >> x >> y >> n;
    // ll mul = 0;
    // ll lo = 1, hi = 1e9;
    // while(lo <= hi)
    // {
    //     ll mid = (lo + hi) / 2;
    //     if(mid * x + y <= n)
    //         mul = mid, lo = mid + 1;
    //     else
    //         hi = mid - 1;
    // }
    // cout << mul * x + y << endl;
    // BS was overkill
    ll num = (n/x)*x + y;
    if(num > n)
    	num -= x;
    cout<<num<<endl;
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