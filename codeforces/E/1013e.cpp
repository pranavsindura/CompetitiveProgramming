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
const int MAXN = 5e3 + 5;

int n;
int arr[MAXN];
int at[MAXN][2];
int dp[MAXN][MAXN / 2][2];

void cp()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++)
    {
        int H = arr[i - 1];
        H = min(H, arr[i] - 1);
        at[i][0] = H;

        H = arr[i + 1];
        H = min(H, arr[i] - 1);
        at[i][1] = H;
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= (n + 1) / 2; j++)
            dp[i][j][0] = dp[i][j][1] = inf;

    for(int i = 0; i <= n; i++)
        dp[i][0][0] = 0;
    dp[1][1][1] = arr[2] - at[1][1];

    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= (n + 1) / 2; j++)
        {
            // Dont make a hill
            dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0], dp[i - 1][j][1]});

            // Make i-th hill a building
            // last was a hill
            int H = at[i - 2][1];
            int T = at[i][0];
            int need = H - min(H, T) + arr[i + 1] - at[i][1];
            dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + need);
            // last was not a hill
            need = arr[i - 1] - at[i][0] + arr[i + 1] - at[i][1];
            dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][0] + need);
        }

    for(int i = 1; i <= (n + 1) / 2; i++)
        cout << min(dp[n][i][0], dp[n][i][1]) << " ";
    cout << endl;
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

