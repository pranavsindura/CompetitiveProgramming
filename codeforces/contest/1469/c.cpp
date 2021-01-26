#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

bool overlap(pi a, pi b)
{
    return max(a.ff, b.ff) <= min(a.ss, b.ss);
}

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    bool ok = true;
    pi prev = {arr[0] + 1, arr[0] + k};
    for(int i = 1; i < n - 1; i++)
    {
        pi me = {arr[i] + 1, arr[i] + k};
        if(prev.ss < me.ff) ok = false;
        else
        {
            ll need = min(k - 1, prev.ff - me.ss);
            need = max(need, 0LL);
            me.ff += need, me.ss += need;
            if(!overlap(prev, me)) ok = false;
            ll lo = 0, hi = k - 1 - need;
            ll can = 0;
            while(lo <= hi)
            {
                ll mid = (lo + hi) >> 1;
                pi here = {me.ff + mid, me.ss + mid};
                if(overlap(here, prev))
                    can = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            me.ss += can;
        }
        prev = me;
    }
    pi me = {arr[n - 1] + 1, arr[n - 1] + k};
    if(!overlap(prev, me)) ok = false;
    cout << (ok ? "YES\n" : "NO\n");
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

