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
    vector<int> A(n), B(m);
    for(int &x : A)
        cin >> x;
    for(int &x : B)
        cin >> x;

    vector<int> P, Q;
    for(int x : A)
        if(x > 0) P.pb(x);
    for(int x : B)
        if(x > 0) Q.pb(x);

    int R = 0, have = 0;
    while(!Q.empty())
    {
        int x = Q.back();
        Q.pop_back();

        while(!P.empty() && P.back() > x) P.pop_back();
        if(P.empty()) continue;

        int can = upper_bound(all(Q), x - sz(P)) - begin(Q);
        can = sz(Q) - can + 1;
        can = min(can, sz(P));
        R = max(R, can + have);

        have += P.back() == x;
    }

    P.clear(), Q.clear();
    for(int x : A)
        if(x < 0) P.pb(-x);
    for(int x : B)
        if(x < 0) Q.pb(-x);
    reverse(all(P)), reverse(all(Q));

    int L = 0;
    have = 0;
    while(!Q.empty())
    {
        int x = Q.back();
        Q.pop_back();

        while(!P.empty() && P.back() > x) P.pop_back();
        if(P.empty()) continue;

        int can = upper_bound(all(Q), x - sz(P)) - begin(Q);
        can = sz(Q) - can + 1;
        can = min(can, sz(P));
        L = max(L, can + have);

        have += P.back() == x;
    }

    cout << L + R << endl;
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
