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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int W, H, T;
vector<vector<vector<int>>> query(101);
vector<int> dx = {0, 0, 1, -1, 0};
vector<int> dy = {1, -1, 0, 0, 0};

int dp[105][105][105];

bool inside(int x, int y, int lx, int ly, int rx, int ry)
{
    return (x >= lx && x <= rx && y >= ly && y <= ry);
}

int solve(int x, int y, int t)
{
    if(t > T)
        return 1;

    int &ret = dp[x][y][t];
    if(~ret)
        return ret;

    for(auto &v : query[t])
        if(inside(x, y, v[0], v[1], v[2], v[3]))
            return ret = 0;

    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(inside(nx, ny, 1, 1, H, W))
            ans |= solve(nx, ny, t + 1);
    }

    return ret = ans;
}

void cp()
{
    int test = 0;
    while(cin >> W >> H >> T && W + H + T)
    {
        for(int i = 1; i <= T; i++)
            query[i].clear();

        int q;
        cin >> q;

        while(q--)
        {
            int stamp, l, t, r, b;
            cin >> stamp >> l >> t >> r >> b;
            query[stamp].pb({t, l, b, r});
        }

        clr(dp, -1);
        for(int i = 1; i <= H; i++)
            for(int j = 1; j <= W; j++)
                solve(i, j, 1);

        vector<pi> pos(T + 1, {-1, -1});

        bool atleast_one = false;
        bool know_one = false;
        for(int k = 1; k <= T; k++)
        {
            int this_time = 0;
            int x, y;
            for(int i = 1; i <= H; i++)
            {
                for(int j = 1; j <= W; j++)
                {
                    int me = dp[i][j][k];
                    atleast_one |= me;
                    this_time += me;
                    if(me)
                        x = i, y = j;
                }
            }
            cout << k << ": " << this_time << endl;
            if(this_time == 1)
                pos[k] = {x, y}, know_one = true;
        }
        
        cout << "Robbery #" << ++test << ":\n";

        if(!atleast_one)
            cout << "The robber has escaped.\n";
        else if(know_one)
        {
            for(int i = 1; i <= T; i++)
                if(~pos[i].ff)
                    cout << "Time step " << i << ": The robber has been at " << pos[i].ss << "," << pos[i].ff << ".\n";
        }
        else
            cout << "Nothing known.\n";
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