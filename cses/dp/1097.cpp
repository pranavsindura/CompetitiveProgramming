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
const int MAXN = 5e3 + 5;
const ll inf = 1e15;
int n;
ll arr[MAXN];
ll dp[MAXN][MAXN][2];
bool vis[MAXN][MAXN][2];
ll solve(int i, int j, int turn)
{
    if(i == j)
        return (turn ? -arr[i] : arr[i]);

    ll &ret = dp[i][j][turn];
    if(vis[i][j][turn])
        return ret;
    vis[i][j][turn] = 1;

    // choose arr[i] or arr[j]
    ll a = solve(i + 1, j, turn ^ 1);
    ll b = solve(i, j - 1, turn ^ 1);
    if(turn == 0)
        a += arr[i], b += arr[j];
    else
        a -= arr[i], b -= arr[j];
    ll ans;
    if(turn == 0)
        ans = max(a, b);
    else
        ans = min(a, b);
    return ret = ans;
}

void cp()
{
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];
    ll ans = solve(0, n - 1, 0);
    cout << (ans + sum) / 2 << endl;
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