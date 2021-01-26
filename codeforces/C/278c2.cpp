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
const int MAXN = 100 + 5;

int n, m;
// which employees can speak ith language
vector<vector<int>> adj(MAXN);

int parent[MAXN];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

int union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(a != b)
        parent[b] = a;
}

int comps()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(find_set(i) == i)
            cnt++;
    }
    return cnt;
}

void cp()
{
    cin >> n >> m;
    bool zero = true;
    for(int i = 1; i <= n; i++)
    {
        make_set(i);
        int s, lang;
        cin >> s;
        for(int j = 0; j < s; j++)
        {
            zero = false;
            cin >> lang;
            adj[lang].pb(i);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j < sz(adj[i]); j++)
            union_set(adj[i][0], adj[i][j]);
    }
    if(!zero)
        cout << comps() - 1;
    else
        cout << n;
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