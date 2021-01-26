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
    vector<int> a, b;
    cin >> n;
    a.resize(n);
    for(int &x : a)
        cin >> x;
    cin >> m;
    b.resize(m);
    for(int &x : b)
        cin >> x;
    int mxa = 0, mxb = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i], mxa = max(mxa, sum);
    sum = 0;
    for(int i = 0; i < m; i++)
        sum += b[i], mxb = max(mxb, sum);
    cout << mxa + mxb << endl;
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

