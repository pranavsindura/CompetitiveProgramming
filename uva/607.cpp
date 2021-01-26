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
int n, L, C;
vector<int> arr;

bool vis[1005][505];
pi dp[1005][505];

int DI(int t)
{
    if(t == 0)
        return 0;
    else if(t <= 10)
        return -C;
    else
        return (t - 10) * (t - 10);
}

pi solve(int i, int time_left)
{
    if(i == n)
        return {0, DI(time_left)};

    if(vis[i][time_left])
        return dp[i][time_left];

    vis[i][time_left] = 1;

    pi ans = {1e9, 1e9};
    if(time_left >= arr[i])
    {
        // try finishing within this lecture
        pi c = solve(i + 1, time_left - arr[i]);
        ans = min(ans, c);
    }

    // start a new lecture for me
    pi c = solve(i + 1, L - arr[i]);
    c.ff++, c.ss += DI(time_left);
    ans = min(ans, c);
    return dp[i][time_left] = ans;
}

void cp()
{
    int test = 0;
    while(cin >> n && n)
    {
        cin >> L >> C;
        arr.resize(n);
        for(int &x : arr)
            cin >> x;

        clr(vis, false);
        pi ans = solve(0, L);
        ans.ff++;
        
        if(test)
            cout << endl;
        cout << "Case " << ++test << ":\n";
        cout << "Minimum number of lectures: " << ans.ff << endl;
        cout << "Total dissatisfaction index: " << ans.ss << endl;
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