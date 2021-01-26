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

int dp[205][405];
int n;
vector<int> arr;
int solve(int pos, int t)
{
    if(pos == n)
        return 0;
    if(t > 2 * n)
        return 1e7;
    int &ret = dp[pos][t];
    if(~ret)
        return ret;

    int ans = 1e7;
    ans = min(ans, solve(pos, t + 1));
    ans = min(ans, abs(arr[pos] - t) + solve(pos + 1, t + 1));

    return ret = ans;
}

void cp()
{
    cin >> n;
    arr.resize(n);
    for(int &x : arr)
        cin >> x;

    vector<bool> avail(2 * n + 1, true);

    sort(all(arr));
    clr(dp, -1);
    int ans = solve(0, 1);

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