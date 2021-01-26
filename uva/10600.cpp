#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
void make_set(int v, vector<int> &p)
{
    p[v] = v;
}
int find_set(int v, vector<int> &p)
{
    return v == p[v] ? v : p[v] = find_set(p[v], p);
}
bool union_set(int a, int b, vector<int> &p)
{
    a = find_set(a, p), b = find_set(b, p);
    if(a != b)
    {
        p[b] = a;
        return true;
    }
    else
        return false;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int cost[105][105];
        vector<pii> edges(m);
        vector<bool> done(m, false);
        vector<int> p(n + 1);
        for(int i = 0; i < sz(p); i++)
            make_set(i, p);
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.pb(mp(a, b));
            cost[a][b] = c;
        }
        sort(all(edges), [&](pii a, pii b)
        {
            return cost[a.ff][a.ss] < cost[b.ff][b.ss];
        });
        vector<int> mst;
        int c1 = 0, c2 = INT_MAX;
        for(int i = 0; i < sz(edges); i++)
        {
            if(union_set(edges[i].ff, edges[i].ss, p))
                mst.pb(i), c1 += cost[edges[i].ff][edges[i].ss];
        }
        for(int i = 0; i < sz(mst); i++)
        {
            for(int k = 0; k < sz(p); k++)
                make_set(k, p);
            int c = 0;
            for(int j = 0; j < sz(edges); j++)
            {
                if(j == mst[i])
                    continue;
                if(union_set(edges[j].ff, edges[j].ss, p))
                    c += cost[edges[j].ff][edges[j].ss];
            }
            if(c >= c1 && c < c2)
                c2 = c;
        }
        cout << c1 << " " << c2 << endl;
    }
    return 0;
}