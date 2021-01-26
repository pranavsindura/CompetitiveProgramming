#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define mt make_tuple
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
const int MAXN = 1e6 + 5;

map<string, int> comp;
int n;
int get_idx(string &s)
{
    if(comp.count(s))
        return comp[s];
    else
        return comp[s] = n++;
}

pi conv[65][65];

void cp()
{
    vector<vector<int>> adj(65);
    vector<bool> vis(65);
    string s;
    while(cin >> s && s[0] != '.')
    {
        if(s[0] == '!')
        {
            int x, y;
            string a, b, c;
            cin >> x >> a >> c >> y >> b;

            int u = get_idx(a), v = get_idx(b);
            int g = __gcd(x, y);
            x /= g, y /= g;

            conv[u][v] = {x, y};
            conv[v][u] = {y, x};
            adj[u].pb(v);
            adj[v].pb(u);
        }
        else
        {
            string a, b, c;
            cin >> a >> c >> b;
            int src = get_idx(a), dest = get_idx(b);
            fill(begin(vis), begin(vis) + n, false);

            vector<pi> ans(n, mp(-1, -1));
            // a,b,u
            // a units of parent, b units of u, at node u
            queue<tuple<int, int, int>> q;
            q.push(mt(1, 1, src));
            while(!q.empty())
            {
                int a, b, u;
                tie(a, b, u) = q.front();
                q.pop();
                vis[u] = 1;
                ans[u] = {a, b};
                for(int v : adj[u])
                {
                    if(!vis[v])
                    {
                        int x = conv[u][v].ff, y = conv[u][v].ss;
                        int lcm = b * x / __gcd(b, x);
                        int need = lcm / b;
                        int na = a * need, nb = b * need * y / x;
                        int g = __gcd(na, nb);
                        na /= g, nb /= g;

                        q.push(mt(na, nb, v));
                        vis[v] = 1;
                    }
                }
            }
            int x = ans[dest].ff;
            int y = ans[dest].ss;
            if(~x)
                cout << x << " " << a << " = " << y << " " << b << endl;
            else
                cout << "? " << a << " = ? " << b << endl;
        }
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