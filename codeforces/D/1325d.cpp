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
    ll S, X;
    cin >> X >> S;

    bool ok = (S >= X) && (S - X) % 2 == 0;
    if(S == X)
    {
        if(S)
            cout << 1 << endl << S << endl;
        else
            cout << 0 << endl;
    }
    else if(ok)
    {
        vector<ll> ans;
        ll A = (S - X) / 2;

        if(X == 0)
            ans = {A, A};
        else if((A & X) == 0)
            ans = {A, A | X};
        else
            ans = {A, A, X};

        cout << sz(ans) << endl;
        for(ll x : ans)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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

