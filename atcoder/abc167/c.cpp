#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
int n, m, x;
int cost[15];
int inc[15][15];
int ans = INT_MAX;

void solve(int pos, vector<int> add, int cost_so_far)
{
    if(pos == n)
    {
        bool ok = true;
        for(int a : add)
            if(a < x)
                ok = false;
        if(ok)
            ans = min(ans, cost_so_far);
    }
    else
    {
        //don't read pos-th book
        solve(pos + 1, add, cost_so_far);
        for(int i = 0; i < m; i++)
            add[i] += inc[pos][i];
        solve(pos + 1, add, cost_so_far + cost[pos]);
    }
}

void cp()
{
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
        for(int j = 0; j < m; j++)
            cin >> inc[i][j];
    }
    solve(0, vector<int>(m, 0), 0);
    if(ans == INT_MAX)
        cout << -1;
    else
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