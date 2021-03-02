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
    string s, t;
    cin >> s >> t;

    vector<int> A(m), B(m);

    int p = 0, q = 0;
    while(p < n && q < m)
    {
        while(p < n && s[p] != t[q]) p++;
        A[q] = p;
        q++, p++;
    }

    p = n - 1, q = m - 1;
    while(p >= 0 && q >= 0)
    {
        while(p >= 0 && s[p] != t[q]) p--;
        B[q] = p;
        q--, p--;
    }

    int ans = 0;
    for(int i = 0; i < m - 1; i++)
        ans = max(ans, B[i + 1] - A[i]);

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
