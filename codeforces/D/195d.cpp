#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pdbl pair<ld, ld>
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

int sg(int a)
{
    return  (a >= 0 ? 1 : -1);
}


void cp()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for(auto &x : arr)
        cin >> x.ff >> x.ss;

    set<pi> breakpoint;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].ff != 0)
        {
            int x = -arr[i].ss, y = arr[i].ff;
            int sg_x = sg(x), sg_y = sg(y);
            x = abs(x), y = abs(y);
            int g = __gcd(x, y);
            x /= g, y /= g;
            if(sg_x != sg_y)
                x = -x;
            breakpoint.insert({x, y});
        }
    }

    cout << sz(breakpoint) << endl;
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