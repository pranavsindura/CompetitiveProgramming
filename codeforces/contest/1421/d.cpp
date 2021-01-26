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
    ll x, y;
    ll c1, c2, c3, c4, c5, c6;
    cin >> x >> y >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

    for(int i = 0; i < 6 * 6 * 6; i++)
    {
        ll _c1 = min(c1, c2 + c6);
        ll _c2 = min(c2, c1 + c3);
        ll _c3 = min(c3, c2 + c4);
        ll _c4 = min(c4, c3 + c5);
        ll _c5 = min(c5, c4 + c6);
        ll _c6 = min(c6, c1 + c5);
        c1 = _c1;
        c2 = _c2;
        c3 = _c3;
        c4 = _c4;
        c5 = _c5;
        c6 = _c6;
    }

    ll ans = LLONG_MAX;
    if(x >= 0 && y >= 0)
    {
        // top right
        // c1, c2 and c6

        // only c1 and excess
        x = abs(x), y = abs(y);
        ll me = min(x, y) * c1;
        if(y > x)
            me += (y - x) * c2;
        else
            me += (x - y) * c6;
        ans = min(ans, me);
    }
    else if(x >= 0 && y <= 0)
    {
        // top left
        // c5 and c6, c1 and c5, c4 and c6
        x = abs(x), y = abs(y);

        // c5 and c6
        ll me = x * c6 + y * c5;
        ans = min(ans, me);
    }
    else if(x <= 0 && y <= 0)
    {
        // bottom left
        // c4, c5 and c3

        //c4 and excess
        x = abs(x), y = abs(y);
        ll me = min(x, y) * c4;
        if(y > x)
            me += (y - x) * c5;
        else
            me += (x - y) * c3;
        ans = min(ans, me);
    }
    else
    {
        // bottom right
        // c2 and c3, c1 and c3, c4 and c2
        x = abs(x), y = abs(y);
        // c2 and c3
        ll me = x * c3 + y * c2;
        ans = min(ans, me);
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}