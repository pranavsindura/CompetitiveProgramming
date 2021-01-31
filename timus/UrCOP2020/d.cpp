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

ll mxw, mxp, a, b;
ll calc(ll w, ll p)
{
    ll extraw = max(0LL, w - mxw) * a * 100;
    ll extrap = max(0LL, p - mxp) * b;
    return extraw + extrap;
}

void cp()
{
    int n, k;
    cin >> n >> k >> mxw >> mxp >> a >> b;

    vector<array<ll, 3>> packages(n);

    for(int i = 0; i < n; i++)
        cin >> packages[i][0] >> packages[i][1], packages[i][2] = i;

    vector<array<ll, 3>> changed = packages;
    for(int i = 0; i < n; i++)
    {
        ll best = calc(packages[i][0], packages[i][1]);
        // change weight
        string W = to_string(packages[i][0]);
        for(int k = 0; k < ln(W); k++)
            {
            	char j = '9';
                char x = W[k];
                W[k] = j;
                ll nw = stoll(W);
                ll p = packages[i][1];
                ll me = calc(nw, p);
                if(me > best)
                    best = me, changed[i] = {nw, p, i};
                W[k] = x;
            }
        // change cost
        string P = to_string(packages[i][1]);
        for(int k = 0; k < ln(P); k++)
            {
            	char j = '9';
                char x = P[k];
                P[k] = j;
                ll w = packages[i][0];
                ll np = stoll(P);
                ll me = calc(w, np);
                if(me > best)
                    best = me, changed[i] = {w, np, i};
                P[k] = x;
            }
    }

    sort(all(changed), [&](array<ll, 3> A, array<ll, 3> B)
    {
        return calc(A[0], A[1]) - calc(packages[A[2]][0], packages[A[2]][1]) > 
        calc(B[0], B[1]) - calc(packages[B[2]][0], packages[B[2]][1]);
    });

    vector<array<ll, 3>> taken;
    for(int i = 0; i < k; i++) taken.push_back(changed[i]);
    for(int i = k; i < n; i++) taken.push_back(packages[changed[i][2]]);

    sort(all(taken), [&](array<ll, 3> A, array<ll, 3> B)
    {
        return A[2] < B[2];
    });

    ld total = 0;
    for(auto &A : taken)
        total += calc(A[0], A[1]);
    total /= 100;

    fix(20);
    cout << total << endl;
    for(auto &A : taken)
        cout << A[0] << " " << A[1] << endl;
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

