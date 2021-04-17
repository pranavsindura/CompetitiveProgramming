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
const int MAXN = 2e5 + 5;

void cp()
{
    int n, W, H;
    cin >> n >> W >> H;
    vector<vector<int>> coord(n);
    map<int, vector<int>> dir[2];
    for(int i = 0; i < n; i++)
    {
        int t, p, off, x, y;
        cin >> t >> p >> off;
        x = p, y = -off;
        if(t == 2) swap(x, y);
        coord[i] = {t, p, off};
        dir[t - 1][x + y].push_back(i);
    }

    for(int i = -MAXN; i <= MAXN; i++)
        for(int j = 0; j < 2; j++)
            if(dir[j].count(i))
                sort(all(dir[j][i]), [&](int a, int b)
            {
                return coord[a][1] < coord[b][1];
            });

    for(int i = 0; i < n; i++)
    {
        int x = coord[i][1], y = -coord[i][2], d = coord[i][0] - 1;
        if(coord[i][0] == 2) swap(x, y);
        int p = lower_bound(all(dir[d][x + y]), i, [&](int a, int b)
        {
            return coord[a][1] < coord[b][1];
        }) - begin(dir[d][x + y]);
        int take = min(sz(dir[d][x + y]) - p - 1, sz(dir[d ^ 1][x + y]));
        if(sz(dir[d ^ 1][x + y]) > take)
        {
            int q = take;
            int j = dir[d ^ 1][x + y][q];
            int a = coord[j][1], b = H;
            if(coord[j][0] == 2) a = W, b = coord[j][1];
            cout << a << " " << b << endl;
        }
        else
        {
            int q = p + take;
            int j = dir[d][x + y][q];
            int a = coord[j][1], b = H;
            if(coord[j][0] == 2) a = W, b = coord[j][1];
            cout << a << " " << b << endl;
        }
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
