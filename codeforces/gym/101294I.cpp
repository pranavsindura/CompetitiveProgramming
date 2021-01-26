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
const ll inf = 1e10;
const int MAXN = 1e6 + 5;

int n, m;
int times[35];
ll dp[35][35][15];

ll solve(int i, int so_far, int j)
{
    if(j >= m)
        return inf;
    if(i == n)
        return 0;

    ll &ret = dp[i][so_far][j];
    if(~ret)
        return ret;

    // place the ith char on the jth button
    ll ans = inf;
    ans = min(ans, (so_far + 1) * times[i] + solve(i + 1, so_far + 1, j));

    // can also try placing on next button
    ans = min(ans, times[i] + solve(i + 1, 1, j + 1));
    return ret = ans;
}

vector<int> trace(int i, int so_far, int j)
{
    if(i == n)
        return vector<int>(m);

    ll c1 = (so_far + 1) * times[i] + solve(i + 1, so_far + 1, j);
    
    ll c2 = times[i] + solve(i + 1, 1, j + 1);

    if(c1 < c2)
    {
        // we need to place ith char on the jth button
        vector<int> res = trace(i + 1, so_far + 1, j);
        res[j]++;
        return res;
    }
    else
    {
        // we need to place ith char on the j+1th button
        vector<int> res = trace(i + 1, 1, j + 1);
        res[j + 1]++;
        return res;
    }
}

void cp()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> times[i];

    clr(dp, -1);
    solve(0, 0, 0);

    vector<int> ans = trace(0, 0, 0);

    for(int x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    freopen("sms.in", "r", stdin);
    freopen("sms.out", "w", stdout);
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}