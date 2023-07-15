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
const int MAXN = 400 + 5;

char grid[MAXN][MAXN];
int count_a[MAXN][MAXN];
vector<int> same[MAXN][MAXN][26];

int sum(int p, int q, int r, int s)
{
    if(p > r || q > s) return 0;
    int ans = count_a[r][s];
    if(p) ans -= count_a[p - 1][s];
    if(q) ans -= count_a[r][q - 1];
    if(p && q) ans += count_a[p - 1][q - 1];
    return ans;
}

void cp()
{
    int n, m, K;
    cin >> n >> m >> K;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            count_a[i][j] = grid[i][j] == 'a';

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            count_a[i][j] += count_a[i][j - 1];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            count_a[i][j] += count_a[i - 1][j];

    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            for(int k = 0; k < n; k++)
                if(grid[k][i] == grid[k][j])
                    same[i][j][grid[k][i] - 'a'].push_back(k);

    ll ans = 0;
    for(int j = 0; j < m; j++)
        for(int k = j + 1; k < m; k++)
        {
            vector<int> cnt(26);
            int r = -1;
            for(int l = 0; l < n; l++)
            {
            	r = max(r, l - 1);
                while(r + 1 < n && sum(l, j, r + 1, k) <= K)
                {
                    if(grid[r + 1][j] == grid[r + 1][k])
                        cnt[grid[r + 1][j] - 'a']++;
                    r++;
                }

                if(grid[l][j] == grid[l][k] && r > l)
                    ans += cnt[grid[l][j] - 'a'] - 1;

                if(grid[l][j] == grid[l][k] && r >= l)
                    cnt[grid[l][j] - 'a']--;
            }
        }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

// 4 5 6 8