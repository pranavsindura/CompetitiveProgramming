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
    string in, out;
    cin >> in >> out;
    bool adj[n][n];
    clr(adj, 0);
    for(int i = 0; i < n; i++)
    {
        if(i + 1 < n)
            adj[i][i + 1] = 1, adj[i + 1][i] = 1;
        if(i > 0)
            adj[i][i - 1] = 1, adj[i - 1][i] = 1;
        adj[i][i] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(in[i] == 'N')
        {
            if(i - 1 >= 0)
                adj[i - 1][i] = 0;
            if(i + 1 < n)
                adj[i + 1][i] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(out[i] == 'N')
        {
            if(i - 1 >= 0)
                adj[i][i - 1] = 0;
            if(i + 1 < n)
                adj[i][i + 1] = 0;
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                    adj[i][j] |= (adj[i][k] & adj[k][j]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << (adj[i][j] ? 'Y' : 'N');
        }
        cout << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << endl;
        cp();
    }
    return 0;
}