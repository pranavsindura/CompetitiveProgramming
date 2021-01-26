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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> deg(n), val(n);
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        cin >> deg[i] >> val[i];
        if(deg[i] == 1)
            q.push(i);
    }
    vector<pi> edge;
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        int v = val[idx];
        if(deg[idx] == 0)
            continue;
        deg[idx]--;
        val[idx] = 0;
        edge.pb({idx, v});
        val[v] ^= idx;
        deg[v]--;
        if(deg[v] == 1)
            q.push(v);
    }
    cout << sz(edge) << endl;
    for(pi x : edge)
        cout << x.ff << " " << x.ss << endl;
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