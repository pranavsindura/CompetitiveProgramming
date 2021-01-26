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
int arr[45][45];
ll pref_sum[45][45];
ll arr_box[45][45][45][45];
ll pref_box[45][45][45][45];

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
        {
            arr[i][j] = s[j - 1] - '0';
        }
    }
    // build prefix sum
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pref_sum[i][j] = pref_sum[i - 1][j] + pref_sum[i][j - 1] - pref_sum[i - 1][j - 1] + arr[i][j];

    // Find Good rectangles
    for(int a = 1; a <= n; a++)
    {
        for(int b = 1; b <= m; b++)
        {
            // Starting points (a,b)
            for(int c = a; c <= n; c++)
            {
                for(int d = b; d <= m; d++)
                {
                    // Ending points (c,d)
                    ll ones = pref_sum[c][d] - pref_sum[a - 1][d] - pref_sum[c][b - 1] + pref_sum[a - 1][b - 1];
                    arr_box[a][b][c][d] = ones == 0;
                }
            }
        }
    }

    // build prefix box
    for(int a = 1; a <= n; a++)
    {
        for(int b = 1; b <= m; b++)
        {
            for(int c = 1; c <= n; c++)
            {
                for(int d = 1; d <= m; d++)
                {
                    pref_box[a][b][c][d] = pref_box[a - 1][b][c][d]
                                           + pref_box[a][b - 1][c][d]
                                           + pref_box[a][b][c - 1][d]
                                           + pref_box[a][b][c][d - 1]
                                           - pref_box[a - 1][b - 1][c][d]
                                           - pref_box[a - 1][b][c - 1][d]
                                           - pref_box[a - 1][b][c][d - 1]
                                           - pref_box[a][b - 1][c - 1][d]
                                           - pref_box[a][b - 1][c][d - 1]
                                           - pref_box[a][b][c - 1][d - 1]
                                           + pref_box[a - 1][b - 1][c - 1][d]
                                           + pref_box[a - 1][b - 1][c][d - 1]
                                           + pref_box[a - 1][b][c - 1][d - 1]
                                           + pref_box[a][b - 1][c - 1][d - 1]
                                           - pref_box[a - 1][b - 1][c - 1][d - 1]
                                           + arr_box[a][b][c][d];
                }
            }
        }
    }

    while(q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = pref_box[c][d][c][d]
                 - pref_box[a - 1][d][c][d]
                 - pref_box[c][b - 1][c][d]
                 - pref_box[c][d][a - 1][d]
                 - pref_box[c][d][c][b - 1]
                 + pref_box[a - 1][b - 1][c][d]
                 + pref_box[a - 1][d][a - 1][d]
                 + pref_box[a - 1][d][c][b - 1]
                 + pref_box[c][b - 1][a - 1][d]
                 + pref_box[c][b - 1][c][b - 1]
                 + pref_box[c][d][a - 1][b - 1]
                 - pref_box[a - 1][b - 1][a - 1][d]
                 - pref_box[a - 1][b - 1][c][b - 1]
                 - pref_box[a - 1][d][a - 1][b - 1]
                 - pref_box[c][b - 1][a - 1][b - 1]
                 + pref_box[a - 1][b - 1][a - 1][b - 1];
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