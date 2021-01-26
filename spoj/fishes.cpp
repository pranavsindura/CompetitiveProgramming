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
    int n, m, h, k, t;
    cin >> n >> m >> h >> k >> t;
    vector<vector<ll>> arr(n, vector<ll>(m)), prod = arr;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j], arr[i][j]--;
    vector<ll> U(k);
    for(int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x;
        for(int j = 0; j < k; j++)
        {
            cin >> y;
            U[j] += x * y;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            prod[i][j] = U[arr[i][j]];
            if(j) prod[i][j] += prod[i][j - 1];
        }
    }
    ll ans = LLONG_MIN;
    for(int i = 0; i < m; i++)
    {
        for(int j = i; j < m; j++)
        {
            ll mx = LLONG_MIN, best = 0;
            for(int a = 0; a < n; a++)
            {
                ll me = prod[a][j] - (i ? prod[a][i - 1] : 0);
                best = max(me, best + me);
                mx = max(mx, best);
            }
            ans = max(ans, mx);
        }
    }
    cout << ans + h << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ":\n";
        cp();
    }
    return 0;
}

