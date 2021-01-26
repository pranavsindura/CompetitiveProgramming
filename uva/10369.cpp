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
double dist(pii a, pii b)
{
    return (a.first - b.first) * (a.first - b.first) * 1.0 + (a.second - b.second) * (a.second - b.second) * 1.0;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int s, p;
        cin >> s >> p;
        vector<pii> coord(p + 1);
        double cost[505][505];
        for(int i = 1; i <= p; i++)
        {
            int a, b;
            cin >> a >> b;
            coord[i] = mp(a, b);
        }
        vector<pii> edge;
        vector<int> parent(p + 1);
        for(int i = 1; i <= p; i++)
            make_set(i, parent);
        for(int i = 1; i <= p; i++)
        {
            for(int j = i + 1; j <= p; j++)
            {
                edge.pb(mp(i, j));
                cost[i][j] = sqrt(dist(coord[i], coord[j]));
                // cout<<cost[i][j]<<" ";
            }
        }
        sort(all(edge), [&](pii a, pii b)
        {
            return cost[a.ff][a.ss] < cost[b.ff][b.ss];
        });
        vector<int> mst;
        int c = 0;
        double ans = 0;
        for(int i = 0; i < sz(edge); i++)
        {
            if(union_set(edge[i].ff, edge[i].ss, parent))
            {
                c++;
                ans = cost[edge[i].ff][edge[i].ss];
                // mst.pb(i);
            }
            if(c == p - s)
                break;
        }
        // for(auto x: edge)
        // 	cout<<x.first<<" "<<x.second<<endl;
        // reverse(all(mst));
        // set<int> se;
        // int i=0;
        // double ans=0;
        // for(i=0;i<sz(mst);i++){
        // 	if(s-sz(se))
        // 	ans = cost[edge[mst[i]].ff][edge[mst[i]].ss];
        // 	cout<<cost[edge[mst[i]].ff][edge[mst[i]].ss]<<" ";
        // }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}