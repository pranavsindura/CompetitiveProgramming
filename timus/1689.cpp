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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

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
    int g, w, b, p, n;
    cin >> g >> w >> b >> p >> n;
    vector<int> worm(g + 1);
    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        worm[x]++;
    }
    for(int i = 1; i <= g; i++)
        worm[i] += worm[i - 1];
    int ans = -1, best = inf;
    for(int i = 0; i < g; i++)
    {
        if(i + b - 1 >= g) break;
        int squash = 0;
        squash += worm[i + p - 1] - (i - w >= 0 ? worm[i - w] : 0);
        squash += worm[i + b - 1] - (max(i - w + b - p, i + p - 1) >= 0 ? worm[max(i - w + b - p, i + p - 1)] : 0);
        if(squash < best)
            best = squash, ans = i;
    }
    assert(~ans);
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
