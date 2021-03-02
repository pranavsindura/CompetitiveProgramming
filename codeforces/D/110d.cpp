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

vector<ll> lucky;

void gen(ll num)
{
    if(num > 2e9) return;
    if(num > 0) lucky.push_back(num);
    gen(num * 10 + 4);
    gen(num * 10 + 7);
}

void cp()
{
    ll pL, pR, vL, vR;
    int k;
    cin >> pL >> pR >> vL >> vR >> k;

    gen(0);
    sort(all(lucky));
    ll total = 0;

    for(int i = 0; i + k - 1 < sz(lucky); i++)
    {
    	bool over = true;
        // p takes min, v takes max
        ll L = pL;
        if(i) L = max(L, lucky[i - 1] + 1);
        ll R = min(pR, lucky[i]);

        over &= R == lucky[i];

        ll dL = max(0LL, R - L + 1);

        L = max(vL, lucky[i + k - 1]);
        R = vR;
        if(i + k < sz(lucky)) R = min(R, lucky[i + k] - 1);

        over &= L == lucky[i];

        ll dR = max(0LL, R - L + 1);

        total += dL * dR;

        // v takes min, p takes max
        L = vL;
        if(i) L = max(L, lucky[i - 1] + 1);
        R = min(vR, lucky[i]);

        over &= R == lucky[i];

        dL = max(0LL, R - L + 1);

        L = max(pL, lucky[i + k - 1]);
        R = pR;
        if(i + k < sz(lucky)) R = min(R, lucky[i + k] - 1);

        over &= L == lucky[i];

        dR = max(0LL, R - L + 1);

        total += dL * dR - over;
    }

    ld ans = ld(total) / ld(pR - pL + 1) / ld(vR - vL + 1);
    fix(20);
    cout << ans << endl;
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
