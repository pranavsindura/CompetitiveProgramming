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
int par[110];
void make_set(int n)
{
    for(int i = 0; i <= n; i++)
        par[i] = i;
}
int find_set(int i)
{
    if(par[i] == i)
        return i;
    else
        return par[i] = find_set(par[i]);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(a != b)
    {
        par[a] = b;
        return true;
    }
    else
        return false;
}
struct Edge
{
    int u, v, c;
    bool operator<(const Edge &p) const
    {
        return c < p.c;
    }
};
vector<Edge> edges;
int edges_taken[110];
int cnt;
int kruskal(int n)
{
    sort(all(edges));
    int cost = 0;
    cnt = 0;
    make_set(n);
    for(int i = 0; i < sz(edges); i++)
    {
        if(union_set(edges[i].u, edges[i].v))
        {
            cost += edges[i].c;
            edges_taken[cnt] = i;
            cnt++;
            if(cnt == n - 1)
                break;
        }
    }
    if(cnt == n - 1)
        return cost;
    else
        return -1;
}

int main()
{
    int t, tc = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case #" << tc++ << " : ";
        edges.clear();
        clr(edges_taken, 0);
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            Edge data;
            cin >> data.u >> data.v >> data.c;
            edges.pb(data);
        }
        int mst_cost = kruskal(n);
        if(mst_cost == -1)
        {
            cout << "No way\n";
        }
        else
        {
            int second_mst_cost = INT_MAX;
            for(int j = 0; j < cnt; j++)
            {
                make_set(n);
                int pick = 0;
                int cost = 0;
                for(int i = 0; i < sz(edges); i++)
                {
                    if(edges_taken[j] != i)
                    {

                        if(union_set(edges[i].u, edges[i].v))
                        {
                            cost += edges[i].c;
                            pick++;
                            if(pick == n - 1)
                                break;
                        }
                    }
                }
                if(pick == n - 1 && cost < second_mst_cost)
                    second_mst_cost = cost;
            }
            if(second_mst_cost == INT_MAX)
                cout << "No second way\n";
            else
                cout << second_mst_cost << endl;
        }
    }
    return 0;
}
