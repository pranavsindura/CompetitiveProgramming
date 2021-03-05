#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> make(n), have(n);
    for(int &x : make)
        cin >> x;

    queue<int> st;
    for(int i = 0; i < n; i++)
        if(make[i] == have[i])
            st.push(i);

    vector<int> press;
    bool ok = true;
    while(!st.empty())
    {
        int x = st.front();
        st.pop();

        if(have[x] != make[x]) continue;

        press.push_back(x);

        have[x]++;
        for(int v : adj[x])
        {
            have[v]++;
            if(have[v] != make[v]) continue;
            st.push(v);
        }
    }
    cout << sz(press) << endl;
    sort(all(press));
    for(int x : press)
        cout << x + 1 << " ";
    cout << endl;
}

int main()
{
    // FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
