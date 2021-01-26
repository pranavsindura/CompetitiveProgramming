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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int inf = 1e6 + 5;
using namespace std;

int n;
int brightness[8];
vector<string> arr;

int dp[8][1 << 11][8];

int solve(int last, int mask, int start)
{
    if(mask == 0)
        return (last == start ? brightness[last] : inf);

    int &ret = dp[last][mask][start];
    if(~ret)
        return ret;
    int ans = inf;
    for(int i = 0; i < n; i++)
    {
        if((mask >> i) & 1)
        {
            int nmask = mask & ~(1 << i);
            for(int j = 0; j < 8; j++)
            {
                if((arr[i][j] - 'A') == last)
                {
                    int nlast = arr[i][(j + 4) % 8] - 'A';
                    int me = brightness[last] + solve(nlast, nmask, start);
                    ans = min(ans, me);
                }
            }
        }
    }
    return ret = ans;
}

void cp()
{
    while(cin >> n && n)
    {
        for(int i = 0; i < 8; i++)
            cin >> brightness[i];
        arr.resize(n);
        for(string &x : arr)
            cin >> x;
        int ans = inf;
        clr(dp, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                int start = arr[i][j] - 'A';
                int last = arr[i][(j + 4) % 8] - 'A';
                int mask = ((1 << (n - 1)) - 1);
                int me = solve(last, mask, start);
                ans = min(ans, me);
            }
        }
        if(ans >= inf)
            cout << "impossible\n";
        else
            cout << ans << endl;
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