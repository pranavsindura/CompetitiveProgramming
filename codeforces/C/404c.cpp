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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> d(n + 5);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        d[x].pb(i);
    }

    if(sz(d[0]) != 1)
    {
        cout << -1;
        return;
    }
    int total_cnt = 1;
    queue<pi> q;
    q.push({d[0].front(), 0});
    int depth = 1, pos = 0;
    vector<pi> edges;
    while(!q.empty())
    {
        int u = q.front().ff;
        int ud = q.front().ss;
        q.pop();

        if(depth <= ud)
        {
            cout << -1;
            return;
        }
        if(depth > ud + 1)
            continue;

        int picked = 0;
        while(picked < k - (ud > 0) && pos < sz(d[depth]))
        {
            q.push({d[depth][pos], depth});
            edges.pb({u, d[depth][pos++]});
            picked++;
            total_cnt++;
        }
        if(pos == sz(d[depth]))
            depth++, pos = 0;
    }
    if(total_cnt == n)
    {
        cout << sz(edges) << endl;
        for(pi x : edges)
            cout << x.ff << " " << x.ss << endl;
    }
    else
        cout << -1;
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