#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 350 + 5;

string s;
vector<vector<int>> adj(MAXN);
/*
	0 -> X
	1 -> R
	2 -> B
*/
ll dp[MAXN][MAXN][3][3];
vector<vector<int>> colour = {{1, 0}, {2, 0}, {0, 1}, {0, 2}};

ll solve(int u, int i, int before, int after)
{
    if(i == sz(adj[u]))
        return 1;

    ll &ret = dp[u][i][before][after];
    if(~ret)
        return ret;

    ll ans = 0;
    int first = 0, last = sz(adj[u]) - 1;

    if(i == last) // check both before and after
    {
        for(int j = 0; j < 4; j++)
        {
            int x = colour[j][0], y = colour[j][1];
            if((!before || (before != x)) and (!after || (after != y)))
                ans += solve(adj[u][i], 0, x, y), ans %= mod;
        }
    }
    else
    {
        for(int j = 0; j < 4; j++)
        {
            int x = colour[j][0], y = colour[j][1];
            if((!before || (before != x)))
                ans += (solve(adj[u][i], 0, x, y) * solve(u, i + 1, y, after)) % mod, ans %= mod;
        }
    }
    return ret = ans;
}

void cp()
{
    cin >> s;
    stack<int> st;
    st.push(0);
    int node = 1;
    for(int i = 0; i < ln(s); i++)
        if(s[i] == '(')
            adj[st.top()].pb(node), st.push(node++);
        else
            st.pop();
    st.pop();

    clr(dp, -1);
    ll ans = solve(0, 0, 0, 0);
    cout << ans << endl;
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