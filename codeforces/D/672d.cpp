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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

vector<ll> arr;

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    arr.resize(n);

    ll sum = 0;
    for(ll &x : arr)
        cin >> x, sum += x;

    ll mean = sum / n;

    ll lo = 0, hi = mean;
    ll can_lo = lo;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        ll need = 0;
        for(ll x : arr)
            if(x < mid)
                need += mid - x;

        if(need <= k)
            can_lo = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }

    lo = mean, hi = 1e9 + 5;
    ll can_hi = hi;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        ll need = 0;
        for(ll x : arr)
            if(x > mid)
                need += x - mid;

        if(need <= k)
            can_hi = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }

    if(can_hi == can_lo && sum % n != 0)
        can_hi++;
    cout << can_hi - can_lo << endl;
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