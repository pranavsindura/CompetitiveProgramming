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
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    ll each;
    if(n == 1)
        each = m;
    else
        each = 2 * (n - 1) * m;

    ll rounds = k / each;
    ll excess = k % each;
    ll mx = LLONG_MIN;
    ll mn = LLONG_MAX;
    ll sergei = 0;

    ll arr[n + 1][m + 1];
    //initialize values
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ll me = 0;
            if(i == 1 || i == n)
                me = rounds;
            else
                me = rounds * 2;
            arr[i][j] = me;
        }
    }
    //finish excess
    if(n == 1)
    {
        for(int j = 1; j <= m && excess; j++)
        {
            arr[1][j]++;
            excess--;
        }
    }
    else
    {
        //go up
        for(int i = 1; i <= n - 1 && excess; i++)
        {
            for(int j = 1; j <= m && excess; j++)
            {
                arr[i][j]++;
                excess--;
            }
        }
        //go down
        for(int i = n; i >= 2 && excess; i--)
        {
            for(int j = 1; j <= m && excess; j++)
            {
                arr[i][j]++;
                excess--;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            mx = max(mx, arr[i][j]);
            mn = min(mn, arr[i][j]);
            if(i == x && j == y)
            	sergei = arr[i][j];
        }
    }
    cout << mx << " " << mn << " " << sergei;
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