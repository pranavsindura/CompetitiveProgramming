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
const int MAXN = 1e3 + 5;

vector<ll> arr(MAXN);

ll dp[MAXN][MAXN];
int n, m;

ll solve(int i, int k)
{
    if(k < 0)
        return INT_MAX;
    if(i == n - 1)
        return 0;

    ll &ret = dp[i][k];
    if(~ret)
        return ret;

    // refuel or dont
    ll choice1 = solve(i + 1, k - 1);
    ll choice2 = INT_MAX;
    if(arr[i])
        choice2 = arr[i] + solve(i + 1, m - 1);
    return ret = min(choice1, choice2);
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        for(int j=0;j<=m;j++)
            dp[i][j] = -1;
    ll end = solve(0, m);
    cout << (end >= (ll)INT_MAX ? -1 : end) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}