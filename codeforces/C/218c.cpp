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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 1e3 + 5;
bool vis[MAXN][MAXN];
int n;
pii arr[105];
void dfs(pii p)
{
    vis[p.ff][p.ss] = true;
    for(int i = 0; i < n; i++)
    {
        if(!vis[arr[i].ff][arr[i].ss])
        {
            if(arr[i].ff == p.ff || arr[i].ss == p.ss)
                dfs(arr[i]);
        }
    }
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = mp(a, b);
    }
    int comp = 0;
    for(int i = 0; i < n; i++)
    {
        if(!vis[arr[i].ff][arr[i].ss])
            dfs(arr[i]), comp++;
    }
    cout << comp - 1;
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