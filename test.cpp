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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void subset(int i, ll x, vector<ll> &A, vector<ll> &S)
{
    if(i == A.size())
        S.push_back(x);
    else
    {
        subset(i + 1, x + A[i], A, S);
        subset(i + 1, x, A, S);
    }
}

void cp()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    const ll MX = 1e10;
    vector<ll> b;
    for(int j = 0; j < n; j++)
    {
        if(b.empty())
        {
            b.push_back(a[j]);
        }
        else
        {
            ll x = b.back() * 2 + a[j];
            if(x > MX) break;
            b.push_back(x);
        }
    }

    vector<ll> L, R;
    int half = (int)b.size() / 2;
    while(b.size() > half)
        R.push_back(b.back()), b.pop_back();
    L = b;

    vector<ll> sub_L, sub_R;
    subset(0, 0, L, sub_L);
    subset(0, 0, R, sub_R);

    sort(sub_L.begin(), sub_L.end());
    sort(sub_R.begin(), sub_R.end());

    cin >> q;
    while(q--)
    {
        ll x;
        cin >> x;
        bool can = false;
        if(x <= MX)
        {
            for(ll a : sub_L)
            {
                if(a > x) break;
                if(binary_search(sub_R.begin(), sub_R.end(), x - a)) can = true;
                if(can) break;
            }
        }
        cout << (can ? "Yes " : "No ");
    }
    cout << endl;
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
