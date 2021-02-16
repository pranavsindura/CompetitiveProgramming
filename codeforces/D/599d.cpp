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
const int inf = 2e6;
const int MAXN = 1e8;

void cp()
{
    ll SQ;
    cin >> SQ;
    ll sum = 0;
    vector<pair<ll, ll>> ans;
    for(ll i = 1; i < MAXN; i++)
    {
        if(i % 2 == 0) sum -= i * i / 4;
        else sum -= (i / 2) * (i / 2 + 1);
        ll half = i / 2 - 1;
        sum -= half * (half + 1);
        if(i & 1) sum -= half + 1;

        ll p = -1;
        ll lo = i, hi = (SQ - sum) * 2 / (i * (i + 1)) + 5;
        while(lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            ll total = i * (i + 1) / 2;
            total *= mid;
            total += sum;
            if(total < SQ) lo = mid + 1;
            else if(total == SQ) p = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        if(~p) ans.push_back({i, p});
        if(~p && i != p) ans.push_back({p, i});
    }
    sort(all(ans));
    cout << sz(ans) << endl;
    for(auto x : ans)
        cout << x.first << " " << x.second << endl;
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
