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
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    ll b;
    cin >> n >> m >> b;
    vector<int> budget(n), price(m);
    for(int &x : budget) cin >> x;
    for(int &x : price) cin >> x;
    sort(all(budget));
    sort(all(price));
    int lo = 0, hi = min(n, m);
    int can = 0;
    ll cost = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        // use last mid people
        int idx = n - mid, j = 0;
        bool ok = true;
        ll excess = 0;
        vector<ll> self;
        for(idx; idx < n; idx++, j++)
        {
            excess += price[j] - min(price[j], budget[idx]);
            self.push_back(min(price[j], budget[idx]));
        }
        if(excess > b) ok = false;
        ll B = b - excess;
        sort(allr(self));
        // pay off max prefix of self
        ll me = 0, total = 0;
        for(int i = 0; i < sz(self); i++)
        {
            ll take = min(B - me, self[i]);
            me += take;
            total += self[i];
        }
        ll pay = total - me;
        if(ok) can = mid, cost = pay, lo = mid + 1;
        else hi = mid - 1;
    }
    cout << can << " " << cost << endl;
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

