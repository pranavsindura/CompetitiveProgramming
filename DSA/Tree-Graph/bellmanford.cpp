#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define clr(x,v) memset(x, v, sizeof(x))
#define sz(x) ((int)x.size())
#define mp make_pair
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
struct edge
{
  int a,b,cost;  
};

bool solve(vector<edge> &e, int n, int st)
{
    vector<int> dist(n+1, INT_MAX);
    dist[st] = 0;
    int m = sz(e);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[e[j].a] < INT_MAX)
            {
                dist[e[j].b] = min(dist[e[j].b], dist[e[j].a] + e[j].cost);
            }
        }
    }
    //dist stores distances from st

    bool change = false;
    for(int j=0;j<m;j++)
    {
        if(dist[e[j].a] < INT_MAX)
        {
            if(dist[e[j].b] > dist[e[j].a] + e[j].cost)
                dist[e[j].b] = dist[e[j].a] + e[j].cost, change = true;
        }
    }
    return change;
    //if change is true, negative cycle exists otherwise not
}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<edge> e;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edge ee = edge{a,b,c};
            e.pb(ee);
        }
        cout<<solve(e, n, e[0].a)<<endl;
    }
    return 0;
}