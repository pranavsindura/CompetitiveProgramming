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
    int test = 1;
    while(cin >> n && n)
    {
        map<string, int> index;
        vector<string> event;
        int idx = 0;

        int adj[205][205] = {0};

        for(int i = 0; i < n; i++)
        {
            int len;
            cin >> len;
            int prev = idx;
            for(int j = 0; j < len; j++)
            {
                string x;
                cin >> x;
                index[x] = idx++;
                event.pb(x);
            }
            for(int j = prev; j < idx - 1; j++)
                adj[j][j + 1] = 1;
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;
            int u = index[a];
            int v = index[b];
            // u->v
            adj[u][v] = 1;
        }
        // Transitive Closure
        for(int k = 0; k < idx; k++)
            for(int i = 0; i < idx; i++)
                for(int j = 0; j < idx; j++)
                    adj[i][j] |= (adj[i][k] & adj[k][j]);
        int cnt = 0;
        vector<string> cons;
        for(int i = 0; i < idx; i++)
        {
            for(int j = i + 1; j < idx; j++)
            {
                if(adj[i][j] == 0 && adj[j][i] == 0)
                {
                    // unreachable from each other, considered concurrent
                    if(cnt < 2)
                        cons.pb("(" + event[i] + "," + event[j] + ")");
                    cnt++;
                }
            }
        }

        if(cnt == 0)
        {
            cout << "Case " << test++ << ", no concurrent events." << endl;
        }
        else
        {
            cout << "Case " << test++ << ", " << cnt << " concurrent events:" << endl;
            for(int i = 0; i < sz(cons); i++)
            {
                cout << cons[i] << " ";
            }
            cout << endl;
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