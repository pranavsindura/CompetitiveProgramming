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
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> parts;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            //go right
            for(int j = 0; j < m; j++)
            {
                parts.pb({i + 1, j + 1});
            }
        }
        else
        {
            //go left
            for(int j = m - 1; j >= 0; j--)
            {
                parts.pb({i + 1, j + 1});
            }
        }
    }
    int tube = 1;
    vector<vector<pii>> ans;
    for(int i = 0; i < sz(parts); i++)
    {
        if(tube <= k)
        {
            ans.pb(vector<pii>());
            ans[sz(ans) - 1].pb(parts[i]);
            ans[sz(ans) - 1].pb(parts[i + 1]);
            i++;
            tube++;
        }
        else
        {
            ans[sz(ans) - 1].pb(parts[i]);
        }
    }
    for(int i = 0; i < sz(ans); i++)
    {
        cout << sz(ans[i]) << " ";
        for(pii x : ans[i])
            cout << x.ff << " " << x.ss << " ";
        cout << endl;
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