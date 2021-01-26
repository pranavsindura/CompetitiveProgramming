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

bool check(ll a, ll b, ll c, ll d)
{
    if(a + b == c + d)
        return true;
    else if(a - b == c - d)
        return true;
    else if(abs(a - c) + abs(b - d) <= 3)
        return true;
    else
        return false;
}
void cp()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll dx = abs(c - a), dy = abs(d - b);
    if(a == c && b == d)
        cout << 0 << endl;
    else if(check(a, b, c, d))
        cout << 1 << endl;
    else if((dx % 2 == dy % 2) || abs(dx - dy) <= 3)
        cout << 2 << endl;
    else
        cout << 3 << endl;
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