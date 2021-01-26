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
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int &x : a)
        cin >> x, x--;
    
    for(int &x : b)
        cin >> x;

    sort(all(a));

    vector<ll> pref(m);
    for(int i = 0; i < m; i++)
        pref[i] = b[i] + (i ? pref[i - 1] : 0);

    ll give = 0;
    for(int i = n - 1; i >= 0; i--) give += b[a[i]];

    ll ans = give;

    int shift = n + m;
    for(int i = n - 1; i >= 0; i--)
    {
        shift--;
        if(shift < 0) break;

        give -= b[a[i]];
        int want = n - i;
        ll me = give + pref[want - 1];
        ans = min(ans, me);

        shift = min(shift, a[i]);
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

