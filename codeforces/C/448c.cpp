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

vector<int> A;

int solve(int l, int r, int x)
{
    if(l > r) return 0;

    int p = min_element(A.begin() + l, A.begin() + r + 1) - begin(A);
    int mn = A[p];

    int ans = min(r - l + 1LL, solve(l, p - 1, mn) + 0LL + solve(p + 1, r, mn) + mn - x);
    return ans;
}

void cp()
{
    int n;
    cin >> n;
    A.resize(n);
    for(int &x : A)
        cin >> x;

    int ans = solve(0, n - 1, 0);

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