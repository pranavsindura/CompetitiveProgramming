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
const int inf = 1e8;
const int MAXN = 1e5 + 5;

int cost[64][64][64];
int dist[64][64][64];
int n, m;

void cp()
{
    int q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                cin >> cost[i][j][k];

    for(int car = 0; car < m; car++)
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    cost[car][i][j] = min(cost[car][i][j], cost[car][i][k] + cost[car][k][j]);

    for(int k = 0; k <= n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[k][i][j] = inf;

    for(int car = 0; car < m; car++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[0][i][j] = min(dist[0][i][j], cost[car][i][j]);

    for(int changes = 1; changes <= n; changes++)
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dist[changes][i][j] = min(dist[changes][i][j], dist[changes - 1][i][k] + dist[0][k][j]);

    for(int changes = 1; changes <= n; changes++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[changes][i][j] = min(dist[changes][i][j], dist[changes - 1][i][j]);

    while(q--)
    {
        int S, T, K;
        cin >> S >> T >> K;
        S--, T--, K = min(K, n - 1);
        cout << dist[K][S][T] << endl;
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
