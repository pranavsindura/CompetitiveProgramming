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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> holes(n + 1, false);
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        holes[x] = true;
    }
    int pos = 1;
    if(holes[1])
        k = 0;
    while(k--)
    {
        int u, v;
        cin >> u >> v;
        if(pos == u)
        {
            if(holes[u])
                break;
            else if(holes[v])
            {
                pos = v;
                break;
            }
            else
                pos = v;
        }
        else if(pos == v)
        {
            if(holes[v])
                break;
            else if(holes[u])
            {
                pos = u;
                break;
            }
            else
                pos = u;
        }
    }
    cout << pos;
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