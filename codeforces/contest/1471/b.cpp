#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    queue<pi> arr;
    for(int i = 0; i < n; i++)
    {
        int  x;
        cin >> x;
        arr.push({1, x});
    }
    ll ans = 0;
    while(!arr.empty())
    {
        pi u = arr.front();
        arr.pop();
        ans += u.ss * u.ff;
        if(u.ss % k == 0)
            arr.push({u.ff * k, u.ss / k});
        else
            break;
    }
    while(!arr.empty())
    {
        pi u = arr.front();
        arr.pop();
        ans += u.ss * u.ff;
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

