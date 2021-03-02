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
    int n;
    ll L, v1, v2;
    cin >> n >> L >> v1 >> v2;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    map<ll, int> M;
    for(int i = 0; i < n; i++)
    {
        ll A = (arr[i] * (v1 + v2) - v2 * L);
        ll B = arr[i] * (v1 + v2);
        if(A < 0)
        {
            A += 2 * L * (v1 + v2);
            B = 2 * L * (v1 + v2);
            M[A]++, M[B]--;
            A = 0, B = arr[i] * (v1 + v2);
            M[A]++, M[B]--;
        }
        else
            M[A]++, M[B]--;
    }

    M[0], M[2 * L * (v1 + v2)];

    vector<pair<ll, int>> pref;
    for(auto x : M) pref.push_back(x);
    for(int i = 1; i < sz(pref); i++)
        pref[i].ss += pref[i - 1].ss;

    vector<double> ans(n + 1);
    for(int i = 0; i < sz(pref) - 1; i++)
        ans[pref[i].ss] += double(pref[i + 1].ff - pref[i].ff) / double(2 * L * (v1 + v2));

    fix(20);
    for(auto x : ans)
        cout << x << endl;
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
