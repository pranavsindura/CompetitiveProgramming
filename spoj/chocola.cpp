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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e3 + 5;

int n, m;
vector<int> row, col;
ll dp[MAXN][MAXN];

ll solve(int i, int j)
{
    if(i == n - 1 && j == m - 1)
        return 0;

    ll &ret = dp[i][j];
    if(~ret)
        return ret;

    ll ans = INT_MAX;

    ll mulrow = j + 1, mulcol = i + 1;
    if(i < n - 1)
        ans = min(ans, mulrow * row[i] + solve(i + 1, j));
    if(j < m - 1)
        ans = min(ans, mulcol * col[j] + solve(i, j + 1));
    return ret = ans;
}

void cp()
{
    cin >> n >> m;
    row.resize(n - 1);
    col.resize(m - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> row[i];
    for(int i = 0; i < m - 1; i++)
        cin >> col[i];

    sort(allr(row));
    sort(allr(col));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = -1;

    ll ans = solve(0, 0);

    cout << ans << endl;
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