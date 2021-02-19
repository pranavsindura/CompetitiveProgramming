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
    int n;
    cin >> n;
    vector<int> arr(n), pos(n);
    for(int &x : arr)
        cin >> x, x--;
    for(int i = 0; i < n; i++)
        pos[arr[i]] = i;
    vector<vector<int>> rmax(n, vector<int>(n));
    for(int i = 0; i < n; i++) rmax[i][i] = arr[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            rmax[i][j] = max(rmax[i][j - 1], arr[j]);

    vector<int> dp(n);
    function<void(int, int, int)> dfs = [&](int l, int r, int h)
    {
        if(l > r) return;
        int mx = rmax[l][r];
        int p = pos[mx];
        dp[p] = h;
        dfs(l, p - 1, h + 1);
        dfs(p + 1, r, h + 1);
    };
    dfs(0, n - 1, 0);
    for(int x : dp)
        cout << x << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
