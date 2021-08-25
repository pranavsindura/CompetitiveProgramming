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

int n;
string A, B;

int dp[MAXN][3][3][3];

int solve(int i, int a, int b, int c)
{
    if(i == n) return 0;

    int ans = 0;
    int &ret = dp[i][a][b][c];
    if(~ret) return ret;

    if(B[i] == '1' && a == 1) ans = max(ans, 1 + solve(i + 1, b, c, A[i + 2] - '0'));
    if(B[i] == '1' && c == 1) ans = max(ans, 1 + solve(i + 1, b, 2, A[i + 2] - '0'));
    if(B[i] == '1' && b == 0) ans = max(ans, 1 + solve(i + 1, 2, c, A[i + 2] - '0'));
    ans = max(ans, solve(i + 1, b, c, A[i + 2] - '0'));

    return ret = ans;
}

void cp()
{
    cin >> n >> A >> B;
    A += "00", B += "00";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                for(int l = 0; l < 3; l++)
                    dp[i][j][k][l] = -1;
    cout << solve(0, 0, A[0] - '0', A[1] - '0') << endl;
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
