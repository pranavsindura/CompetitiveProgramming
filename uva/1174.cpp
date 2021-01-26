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
vector<vector<int>> cost(2005, vector<int>(2005, INT_MAX));

int findInd(map<string, int> &ind, string a, int &count)
{
    if(ind.find(a) != ind.end())
    {
        return ind[a];
    }
    else
    {
        ind[a] = count;
        return count++;
    }
}

void make_set(int i, vector<int> &par)
{
    par[i] = i;
}

int find_set(int v, vector<int> &par)
{
    return (v == par[v] ? v : par[v] = find_set(par[v], par));
}

bool union_set(int a, int b, vector<int> &par)
{
    a = find_set(a, par), b = find_set(b, par);
    if(a != b)
    {
        par[b] = a;
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
        fill(all(cost), vector<int>(2005, INT_MAX));
        int n, m;
        cin >> n >> m;
        map<string, int> ind;
        int count = 0;
        vector<pii> edge;
        for(int i = 0; i < m; i++)
        {
            string a, b;
            int c;
            cin >> a >> b >> c;
            cost[findInd(ind, a, count)][findInd(ind, b, count)] = min(cost[findInd(ind, a, count)][findInd(ind, b, count)], c);
            edge.pb(mp(findInd(ind, a, count), findInd(ind, b, count)));
        }
        sort(all(edge), [&](pii a, pii b)
        {
            return cost[a.ff][a.ss] < cost[b.ff][b.ss];
        });
        int total = 0;
        vector<int> par(n);
        for(int i = 0; i < n; i++)
            make_set(i, par);
        for(int i = 0; i < sz(edge); i++)
        {
            if(union_set(edge[i].ff, edge[i].ss, par))
                total += cost[edge[i].ff][edge[i].ss];
        }
        cout << total << endl;
        if(t)
            cout << endl;
    }
    return 0;
}