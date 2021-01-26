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
const int MAXN = 1e2 + 5;

int arr[MAXN], inv[MAXN];

bool dp[MAXN][MAXN * MAXN];

void cp()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i], arr[i]--;

    int total = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j < i; j++)
            cnt += (arr[j] > arr[i]);
        for(int j = i + 1; j <= n; j++)
            cnt += (arr[i] > arr[j]);
        inv[i] = cnt;
        total += cnt;
    }
    clr(dp, false);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= total; j++)
        {
            if(j >= inv[i])
                dp[i][j] |= dp[i - 1][j - inv[i]];
            dp[i][j] |= dp[i - 1][j];
        }
    }

    bool ok = dp[n][total / 2];

    cout << (ok ? "YES\n" : "NO\n");
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