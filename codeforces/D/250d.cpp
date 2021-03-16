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
    int n, m;
    ll a, b;
    cin >> n >> m >> a >> b;
    vector<pi> A(n);
    vector<pi> B(m);
    for(auto &x : A)
        cin >> x.first;
    for(int i = 0; i < n; i++) A[i].second = i;
    for(auto &x : B)
        cin >> x.first;
    for(auto &x : B)
        cin >> x.second;

    ll bestA = -1, bestB = -1;
    ld bestDist = DBL_MAX;

    auto check = [&](int i, int j)
    {
        ld D = sqrtl(A[i].first * A[i].first + a * a);
        D += B[j].second;
        D += sqrtl((A[i].first - B[j].first) * (A[i].first - B[j].first) + (a - b) * (a - b));
        if(D < bestDist)
            bestA = A[i].second, bestB = j, bestDist = D;
    };

    sort(all(A));
    for(int i = 0; i < m; i++)
    {
        ll y = a * B[i].first / b;
        int idx = lower_bound(all(A), mp(y, -1LL)) - begin(A);
        if(idx - 2 >= 0) check(idx - 2, i);
        if(idx - 1 >= 0) check(idx - 1, i);
        if(idx < n) check(idx, i);
        if(idx + 1 < n) check(idx + 1, i);
        if(idx + 2 < n) check(idx + 2, i);
    }

    cout << bestA + 1 << " " << bestB + 1 << endl;
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
