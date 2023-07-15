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

vector<string> rotate(vector<string> &a)
{
    vector<string> x = a;
    for(int i = 0; i < sz(a); i++)
        for(int j = 0; j < sz(a[0]); j++)
            x[j][sz(a) - i - 1] = a[i][j];
    return x;
}

vector<string> shift_up(vector<string> &a)
{
    int up = sz(a);
    for(int i = 0; i < sz(a); i++)
        for(int j = 0; j < sz(a[0]); j++)
            if(a[i][j] == '#')
                up = min(up, i);

    vector<string> x = vector<string>(sz(a), string(sz(a), '.'));
    for(int i = up; i < sz(a); i++)
        for(int j = 0; j < sz(a[0]); j++)
            x[i - up][j] = a[i][j];

    return x;
}

vector<string> shift_left(vector<string> &a)
{
    int left = sz(a);
    for(int i = 0; i < sz(a); i++)
        for(int j = 0; j < sz(a[0]); j++)
            if(a[i][j] == '#')
                left = min(left, j);

    vector<string> x = vector<string>(sz(a), string(sz(a), '.'));
    for(int i = 0; i < sz(a); i++)
        for(int j = left; j < sz(a[0]); j++)
            x[i][j - left] = a[i][j];

    return x;
}

void cp()
{
    int n;
    cin >> n;
    vector<string> S(n), T(n);
    for(string &x : S)
        cin >> x;
    for(string &x : T)
        cin >> x;

    bool ok = false;

    S = shift_up(S);
    S = shift_left(S);

    T = shift_up(T);
    T = shift_left(T);

    ok |= S == T;

    T = rotate(T);
    T = shift_up(T);
    T = shift_left(T);

    ok |= S == T;

    T = rotate(T);
    T = shift_up(T);
    T = shift_left(T);

    ok |= S == T;

    T = rotate(T);
    T = shift_up(T);
    T = shift_left(T);

    ok |= S == T;

    cout << (ok ? "Yes\n" : "No\n");
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
