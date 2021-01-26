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

void cp()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].ff >> arr[i].ss;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        map<pi, int> slope;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            int x, y;
            x = arr[j].ff - arr[i].ff;
            y = arr[j].ss - arr[i].ss;
            if(x && y)
            {
                int sg_x = (x >= 0 ? 1 : -1);
                int sg_y = (y >= 0 ? 1 : -1);
                x = abs(x), y = abs(y);
                int g = __gcd(x, y);
                x /= g, y /= g;
                x *= sg_x, y *= sg_y;
                slope[mp(y, x)]++;
            }
            else if(x)
            {
                slope[mp(0, 1)]++;
            }
            else if(y)
            {
                slope[mp(1, 0)]++;
            }
        }
        for(auto x : slope)
            if(x.ss >= 2)
                ok  = 1;
    }
    cout << (ok ? "Yes\n" : "No\n");
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