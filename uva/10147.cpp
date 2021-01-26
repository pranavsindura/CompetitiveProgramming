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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

void make_set(int v, vector<int> &parent, vector<int> &rank)
{
    parent[v] = v;
    rank[v] = 0;
}
int find_set(int v, vector<int> &parent)
{
    if(parent[v] == v)
        return v;
    else
        return parent[v] = find_set(parent[v], parent);
}
bool union_set(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a != b)
    {
        parent[b] = a;
        return true;
    }
    else
        return false;
}
ll dist(pii a, pii b)
{
    return (a.first - b.first) * 1LL * (a.first - b.first) + (a.second - b.second) * 1LL * (a.second - b.second);
}
ll cost[755][755] = {0};
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pii> coord(n + 1);
        vector<int> parent(n + 1), rank(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            coord[i] = mp(a, b);
            make_set(i, parent, rank);
        }
        int m;
        cin >> m;
        int ec = 0;
        for(int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            if(union_set(a, b, parent, rank))
                ec++;
        }
        if(ec == n - 1)
        {
            cout << "No new highways need" << endl;
        }
        else
        {
            vector<pii> edge;
            for(int i = 1; i <= n; i++)
            {

                for(int j = i + 1; j <= n; j++)
                {
                    edge.pb(mp(i, j));
                    cost[i][j] = dist(coord[i], coord[j]);
                    cost[j][i] = dist(coord[i], coord[j]);
                }
            }
            sort(all(edge), [&](pii a, pii b)
            {
                return cost[a.first][a.second] < cost[b.first][b.second];
            });
            for(int i = 0; i < sz(edge); i++)
            {
                if(union_set(edge[i].first, edge[i].second, parent, rank))
                {
                    cout << edge[i].first << " " << edge[i].second << endl;
                }
            }
        }
        if(t)
            cout << endl;
    }
    return 0;
}