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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int pref_row[1005][1005], pref_col[1005][1005];

int sum(int a, int b, int c, bool row)
{
    int total = 0;
    if(b > c)
        return 0;
    if(row)
        //sum from col b to col c in row a
        total = (b > 0 ? pref_row[a][c] - pref_row[a][b - 1] : pref_row[a][c]);
    else
        //sum from row b to row c in col a
        total = (b > 0 ? pref_col[c][a] - pref_col[b - 1][a] : pref_col[c][a]);
    return total;
};

void cp()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            pref_row[i][j] = (arr[i][j] == '*') + (j ? pref_row[i][j - 1] : 0);

    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            pref_col[i][j] = (arr[i][j] == '*') + (i ? pref_col[i - 1][j] : 0);

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.')
                continue;

            int up = sum(j, 0, i - 1, 0);
            int down = sum(j, i + 1, n - 1, 0);
            int left = sum(i, 0, j - 1, 1);
            int right = sum(i, j + 1, m - 1, 1);

            ll me = 0;
            me += up * 1LL * left;
            me += up * 1LL * right;
            me += down * 1LL * left;
            me += down * 1LL * right;

            ans += me;
        }
    }
    cout << ans;
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