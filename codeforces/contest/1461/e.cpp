#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    bool ok = true, fill = false;
    // first day
    if(x <= k)
    {
        if(k - x >= l) {} //ok, no need to fill
        else
        {
            // need to fill
            if(k + y > r) ok = false;
            else k += y, fill = true;
            if(k - x < l) ok = false;
        }
    }
    else
    {
        // need to fill
        if(k + y > r) ok = false;
        else k += y, fill = true;
        if(k - x < l) ok = false;
    }
    // cannot sustain first day
    if(!ok)
    {
        cout << "No\n";
        return;
    }

    t--;
    k -= x;

    if(t == 0 || x == y)
    {
        cout << "Yes\n";
        return;
    }
    // x > y
    // x < y
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

