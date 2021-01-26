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
const int MAXN = 1e3 + 5;

bool ban[MAXN][MAXN];

void cp()
{
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> x >> y, ban[x - 1][y - 1] = true;

    int ans = 2 * (n - 2) - (n & 1);

    int blocked_r = 0, blocked_c = 0;
    bool blocked_middle_r = false, blocked_middle_c = false;

    // Find blocked rows
    for(int i = 1; i < n - 1; i++)
    {
        bool ok = true;
        for(int j = 0; j < n; j++)
            if(ban[i][j])
                ok = false;

        if((n & 1) && i == n / 2)
            blocked_middle_r |= !ok;
        else
            blocked_r += !ok;
    }

    // Find blocked cols
    for(int j = 1; j < n - 1; j++)
    {
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(ban[i][j])
                ok = false;

        if((n & 1) && j == n / 2)
            blocked_middle_c |= !ok;
        else
            blocked_c += !ok;
    }
    ans -= blocked_r + blocked_c;
    if(blocked_middle_r && blocked_middle_c)
        ans--;
    cout << ans;
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