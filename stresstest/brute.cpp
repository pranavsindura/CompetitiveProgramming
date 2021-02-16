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
const int inf = 1e9;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    vector<pi> A;
    for(int &x : arr)
        cin >> x;

    auto get_max = [&](multiset<int> X, multiset<int> Y)
    {
        int mx = -inf, val;
        auto Fx = X.begin();
        auto Sx = X.rbegin();
        auto Fy = Y.begin();
        auto Sy = Y.rbegin();
        if(sz(X) >= 2) val = *(++Sx) + *(--Sx), mx = max(mx, val);
        if(sz(Y) >= 2) val = *(++Sy) + *(--Sy), mx = max(mx, val);
        if(sz(X) >= 1 && sz(Y) >= 1) mx = max(mx, *Sx + *Sy + h);
        return mx;
    };

    auto get_min = [&](multiset<int> X, multiset<int> Y)
    {
        int mn = inf;
        auto Fx = X.begin();
        auto Sx = X.rbegin();
        auto Fy = Y.begin();
        auto Sy = Y.rbegin();
        if(sz(X) >= 2) mn = min(mn, *Fx + * (++Fx)), Fx--;
        if(sz(Y) >= 2) mn = min(mn, *Fy + * (++Fy)), Fy--;
        if(sz(X) >= 1 && sz(Y) >= 1) mn = min(mn, *Fx + *Fy + h);
        return mn;
    };

    int ans = 1e9;
    vector<int> res(n);
    int bestmask = -1;
    for(int mask = 0; mask < 1 << n; mask++)
    {
        multiset<int> X, Y;
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1) Y.insert(arr[i]);
            else X.insert(arr[i]);
        int mx = get_max(X, Y);
        int mn = get_min(X, Y);
        if(mx - mn <= ans)
            ans = mx - mn, bestmask = mask;
    }
    for(int i = 0; i < n; i++)
        res[i] = (bestmask >> i) & 1;

    cout << ans << endl;
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
