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
const int MAXN = 1e6 + 5;

struct edge
{
    int wt, was_included, idx;
    edge() {}
    edge(int wt, int was_included, int idx): wt(wt), was_included(was_included), idx(idx) {}
    const bool operator<(const edge &e) const
    {
        if(wt != e.wt)
            return wt < e.wt;
        else
            return was_included > e.was_included;
    }
};

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.pb(edge(a, b, i));
    }

    sort(all(edges));
    int u = 2;
    queue<pi> allowed;
    vector<pi> ans(m);
    bool ok = true;

    for(edge e : edges)
    {
        if(e.was_included)
        {
            ans[e.idx] = {1, u};
            if(u > 2)
                allowed.push({2, u});
            u++;
        }
        else
        {
            if(!allowed.empty())
            {
                pi avail = allowed.front();
                allowed.pop();
                ans[e.idx] = avail;
                avail.ff++;
                if(avail.ff < avail.ss)
                    allowed.push(avail);
            }
            else
                ok = false;
        }
    }
    if(ok)
    {
        for(auto x : ans)
            cout << x.ff << " " << x.ss << endl;
    }
    else
        cout << -1 << endl;
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