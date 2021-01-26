#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<signed, null_type, less_equal<signed>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//find_by_order();
//order_of_key();
 
#define PB  push_back
#define ALL(x)  (x).begin(), (x).end()
#define ALLR(x) (x).rbegin(), (x).rend()
#define MP  make_pair
 
#define debug(_x)       cerr << #_x << '=' << (_x) << endl;
#define debug2(_x, _y)  cerr << #_x << '=' << (_x) << ' ' << #_y << '=' << (_y) << endl;
#define debugn(_a)      cerr << #_a << ": "; for (const auto _x: _a) cerr << (_x) << ' '; cerr << endl;

#define HERE debug(__LINE__);

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)

#define int long long int

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;

const int INF = LONG_LONG_MAX>>1;
const int NINF = LONG_LONG_MIN/2;
const double PI = 3.141592653589793238;


//MODULAR ARITHMATIC
const int mmod = 1000000007;

int add(int a, int b, int m=mmod) {
    return (a%m + b%m)%m;
}

int sub(int a, int b, int m=mmod) {
    return (a%m - b%m + m)%m;
}

int mul(int a, int b, int m=mmod) {
    return ((a%m) * (b%m) % m);
}

int pow(int a, int b, int m=mmod) {
    a %= m;
    int r = 1;
    while (b) {
        if (b&1) r = r*a%m;
        b >>= 1;
        a = a*a%m;
    }
    return r;
}

int inv(int a, int m=mmod) {
    return pow(a, m-2, m);
}

ii norm(int a, int b) {
    int g = __gcd(a, b);
    a /= g, b /= g;
    if (a == 0) b = 1;
    if (b == 0) a = 1;
    if (a < 0) a = -a, b = -b;
    return {a, b};
}

ii inv(ii p) {
    return norm(-p.second, p.first);
}

int pw[200010];

int32_t main() {
    FAST_IO;
    pw[0] = 1;
    for(int i = 1; i < 2e5 + 7; i++)
        pw[i] = pw[i - 1] * 2 % mmod;
        
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    int ans = 0;
    map<ii, int> cnt, vis;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) ans++;
        else {
            ii p = norm(a[i], b[i]);
            cnt[p]++;
        }
    }
    int tt = 1;
    for (auto pp: cnt) {
        ii p = pp.first, q = inv(p);
        if (vis[p]) continue;
        tt = mul(tt, sub(add(pw[cnt[p]], pw[cnt[q]]), 1));
        vis[p] = vis[q] = 1;
    }
    ans = add(ans, tt);
    ans = sub(ans, 1);
    cout << ans << endl;
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined

