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
const ll inf = 1e16;
const int MAXN = 1e2 + 5;

ll cost[105][505];
ll pref[105][505], suff[MAXN][505];
int arr[500005];
int val[500005];
int n, K, D;

void cp()
{
    cin >> n >> K >> D;
    for(int i = 0; i < n; i++)
        cin >> arr[i], arr[i] %= D;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < n; i++)
        cost[i % K][arr[i]] += val[i];

    for(int i = 0; i < K; i++)
    {
        ll total = 0;
        for(int j = 0; j < D; j++)
            total += cost[i][j];
        for(int j = 0; j < D; j++)
            cost[i][j] = total - cost[i][j];
    }

    for(int i = 0; i <= K; i++)
        for(int m = 0; m < D; m++)
            suff[i][m] = inf;
    suff[K][0] = 0;

    for(int i = K - 1; i >= 0; i--)
        for(int m = 0; m < D; m++)
            for(int k = 0; k < D; k++)
                suff[i][m] = min(suff[i][m], cost[i][k] + suff[i + 1][(m + k) % D]);

    for(int i = 0; i <= K; i++)
        for(int m = 0; m < D; m++)
            pref[i][m] = inf;

    for(int m = 0; m < D; m++)
        pref[0][m] = cost[0][m];

    for(int i = 1; i < K; i++)
        for(int m = 0; m < D; m++)
            for(int k = 0; k < D; k++)
                pref[i][m] = min(pref[i][m], cost[i][k] + pref[i - 1][(m - k + D) % D]);

    for(int x = 0; x < K; x++)
        for(int v = 0; v < D; v++)
        {
            ll ans = inf;
            if(x == 0)
                ans = suff[1][v] + cost[0][v];
            else
            {
                for(int m = 0; m < D; m++)
                {
                    ll L = pref[x - 1][m];
                    ll R = suff[x + 1][(m + v) % D];
                    ans = min(ans, L + R + cost[x][v]);
                }
            }
            cost[x][v] = ans;
        }

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        x--;
        cout << cost[x % K][arr[x]] << endl;
    }
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
