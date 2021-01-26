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
int n, m, k;
char arr[7][7];
int ans;
vector<pi> pick;
void rec(int i, vector<pi> subset)
{
    if(i == sz(pick))
    {
        vector<int> row, col;
        for(pi x : subset)
            if(x.ss == 1)
                row.pb(x.ff);
            else
                col.pb(x.ff);
        char temp[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                temp[i][j] = arr[i][j];
        for(int r : row)
            for(int j = 0; j < m; j++)
                temp[r][j] = 'R';
        for(int c : col)
            for(int i = 0; i < n; i++)
                temp[i][c] = 'R';
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            	if(temp[i][j] == '#')
            		cnt++;
        if(cnt == k)
        	ans++;
    }
    else
    {
        rec(i + 1, subset);
        subset.pb(pick[i]);
        rec(i + 1, subset);
    }
}



void cp()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        pick.pb({i, 1});
    for(int i = 0; i < m; i++)
        pick.pb({i, 2});
    rec(0,vector<pi>());
    cout<<ans;
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