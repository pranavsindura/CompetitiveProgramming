#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

double dp[105][105][105];

double solve(int r, int s, int p)
{
    for(int i = 0; i <= r; i++)
        for(int j = 0; j <= s; j++)
            for(int k = 0; k <= p; k++)
            {
                if(i > 0) dp[i][j][k] += dp[i - 1][j][k] * i * k;
                if(k > 0) dp[i][j][k] += dp[i][j][k - 1] * j * k;
                if(j > 0) dp[i][j][k] += dp[i][j - 1][k] * j * i;
                if(i * j + i * k + j * k)
                    dp[i][j][k] /= double(i * j + i * k + j * k);
            }
    return dp[r][s][p];
}

void cp()
{
    int r, s, p;
    cin >> r >> s >> p;

    clr(dp, 0);
    for(int i = 1; i <= r; i++) dp[i][0][0] = 1;
    double a = solve(r, s, p);

    clr(dp, 0);
    for(int i = 1; i <= s; i++) dp[0][i][0] = 1;
    double b = solve(r, s, p);

    clr(dp, 0);
    for(int i = 1; i <= p; i++) dp[0][0][i] = 1;
    double c = solve(r, s, p);

    dblout(10);
    cout << a << " " << b << " " << c << endl;
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