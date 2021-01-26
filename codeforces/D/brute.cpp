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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<vector<int>>> store(q + 1);
    vector<vector<int>> arr(n, vector<int>(m));
    store[0] = arr;
    for(int i = 1; i <= q; i++)
    {
        int t, x, y, k;
        cin >> t;
        if(t == 1)
        {
            cin >> x >> y;
            x--, y--;
            arr[x][y] = 1;
        }
        else if(t == 2)
        {
            cin >> x >> y;
            x--, y--;
            arr[x][y] = 0;
        }
        else if(t == 3)
        {
            cin >> x;
            x--;
            for(int j = 0; j < m; j++)
                arr[x][j] ^= 1;
        }
        else
        {
            cin >> k;
            arr = store[k];
        }
        store[i] = arr;
        int ans = 0;
        for(int a = 0; a < n; a++)
            for(int b = 0; b < m; b++)
                ans += arr[a][b];
        cout << ans << endl;
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

