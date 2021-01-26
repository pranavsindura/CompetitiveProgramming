#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 5000 + 5;
vector<vector<pi>> group(MAXN);
int n, m;

void cp()
{
    cin >> n >> m;
    vector<pi> edge;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge.pb({a, b});
    }
    int x = 1, y = 1;
    for(int i = 1; i <= n; i++)
    {
        group[i].pb({x++, y++});
    }
    for(pi e : edge)
    {
        group[e.ff].pb({e.ff, y});
        group[e.ss].pb({e.ss, y++});
    }
    for(vector<pi> g : group)
    {
        if(sz(g))
        {
            cout << sz(g) << endl;
            for(pi coord : g)
                cout << coord.ff << " " << coord.ss << endl;
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