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
const int MAXN = 105;
ll brightness[MAXN][MAXN][15];
int star[MAXN][MAXN];

ll sum(int p, int q, int r, int s, ll arr[][MAXN][15], int init)
{
    ll ans = arr[r][s][init] - arr[p - 1][s][init] - arr[r][q - 1][init] + arr[p - 1][q - 1][init];
    return ans;
}

void cp()
{
    int n, q, c;
    cin >> n >> q >> c;
    for(int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        brightness[x][y][s]++;
    }
    //sum up rows
    for(int init = 0; init <= 10; init++)
    {
        for(int i = 1; i < MAXN; i++)
        {
            for(int j = 1; j < MAXN; j++)
            {
                brightness[i][j][init] += brightness[i][j - 1][init];
            }
        }
    }
    //sum up cols
    for(int init = 0; init <= 10; init++)
    {
        for(int i = 1; i < MAXN; i++)
        {
            for(int j = 1; j < MAXN; j++)
            {
                brightness[i][j][init] += brightness[i - 1][j][init];
            }
        }
    }
    while(q--)
    {
        ll t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll total_brightness = 0;
        for(int i = 0; i <= c; i++)
        {
            total_brightness += ((i + t) % (c + 1)) * sum(x1, y1, x2, y2, brightness, i);
        }
        cout << total_brightness << endl;
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