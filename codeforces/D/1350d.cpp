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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    bool ok = false;

    for(int i = 0; i < n - 1; i++)
        ok |= count_if(arr.begin() + i, arr.begin() + i + 2, [&](int a)
    {
        return a >= k;
    }) >= 2;
    for(int i = 0; i < n - 2; i++)
        ok |= count_if(arr.begin() + i, arr.begin() + i + 3, [&](int a)
    {
        return a >= k;
    }) >= 2;

    if(n == 1) ok = true;
    ok &= count(all(arr), k) > 0;

    cout << (ok ? "yes\n" : "no\n");
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
