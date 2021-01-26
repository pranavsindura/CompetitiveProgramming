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
const int MAXN = 4e2 + 5;
const int OFF = 4e2;

char arr[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
int d1[2 * MAXN][MAXN];
int d2[2 * MAXN][MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(arr[i][j] == '1')
                row[i][j]++, col[j][i]++, d1[i + j][i]++, d2[i - j + OFF][i]++;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            row[i][j] += row[i][j - 1];
    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++)
            col[j][i] += col[j][i - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d1[i + j][i] += d1[i + j][i - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d2[i - j + OFF][i] += d2[i - j + OFF][i - 1];

    auto valid = [&](int x, int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            // a
            for(int k = 1; valid(i, j + k) && valid(i + k, j); k++)
            {
                if(row[i][j + k] - row[i][j - 1]) continue;
                if(col[j][i + k] - col[j][i - 1]) continue;
                if(d1[i + j + k][i + k] - d1[i + j + k][i - 1]) continue;
                ans++;
            }
            // b
            for(int k = 1; valid(i + k, j) && valid(i, j - k); k++)
            {
                if(row[i][j] - row[i][j - k - 1]) continue;
                if(col[j][i + k] - col[j][i - 1]) continue;
                if(d2[i - j + k + OFF][i + k] - d2[i - j + k + OFF][i - 1]) continue;
                ans++;
            }
            // c
            for(int k = 1; valid(i, j - k) && valid(i - k, j); k++)
            {
                if(row[i][j] - row[i][j - k - 1]) continue;
                if(col[j][i] - col[j][i - k - 1]) continue;
                if(d1[i + j - k][i] - d1[i + j - k][i - k - 1]) continue;
                ans++;
            }
            // d
            for(int k = 1; valid(i - k, j) && valid(i, j + k); k++)
            {
                if(row[i][j + k] - row[i][j - 1]) continue;
                if(col[j][i] - col[j][i - k - 1]) continue;
                if(d2[i - k - j + OFF][i] - d2[i - k - j + OFF][i - k - 1]) continue;
                ans++;
            }
            // d + c
            for(int k = 1; valid(i, j + k) && valid(i - k, j) && valid(i, j - k); k++)
            {
                if(row[i][j + k] - row[i][j - k - 1]) continue;
                if(d1[i + j - k][i] - d1[i + j - k][i - k - 1]) continue;
                if(d2[i - j - k + OFF][i] - d2[i - j - k + OFF][i - k - 1]) continue;
                ans++;
            }
            // c + b
            for(int k = 1; valid(i + k, j) && valid(i, j - k) && valid(i - k, j); k++)
            {
                if(col[j][i + k] - col[j][i - k - 1]) continue;
                if(d2[i - j + k + OFF][i + k] - d2[i - j + k + OFF][i - 1]) continue;
                if(d1[i + j - k][i] - d1[i + j - k][i - k - 1]) continue;
                ans++;
            }
            // b + a
            for(int k = 1; valid(i, j - k) && valid(i + k, j) && valid(i, j + k); k++)
            {
                if(row[i][j + k] - row[i][j - k - 1]) continue;
                if(d1[i + j + k][i + k] - d1[i + j + k][i - 1]) continue;
                if(d2[i - j + k + OFF][i + k] - d2[i - j + k + OFF][i - 1]) continue;
                ans++;
            }
            // a + d
            for(int k = 1; valid(i - k, j) && valid(i, j + k) && valid(i + k, j); k++)
            {
                if(col[j][i + k] - col[j][i - k - 1]) continue;
                if(d1[i + j + k][i + k] - d1[i + j + k][i - 1]) continue;
                if(d2[i - k - j + OFF][i] - d2[i - k - j + OFF][i - k - 1]) continue;
                ans++;
            }
        }
    }
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

