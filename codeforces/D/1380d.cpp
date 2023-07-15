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
const ll inf = 1e16;
const int MAXN = 1e5 + 5;

void cp()
{
    int N, M;
    ll X, K, Y;
    cin >> N >> M >> X >> K >> Y;
    vector<int> A(N), B(M);
    for(int &x : A)
        cin >> x;
    for(int &x : B)
        cin >> x;

    bool ok = true;

    if(N < M) ok = false;

    int p = 0, q = 0;
    while(p < N && q < M)
        if(A[p] == B[q]) p++, q++;
        else p++;

    if(q < M) ok = false;

    if(!ok)
    {
        cout << -1 << endl;
        return;
    }

    map<int, int> idx;
    for(int i = 0; i < N; i++)
        idx[A[i]] = i;

    ll ans = 0;
    vector<int> conv;
    for(int i = 0; i < idx[B[0]]; i++)
    	conv.push_back(A[i]);

    int big = any_of(all(conv), [&](int a){ return a > B[0]; });
    int small = sz(conv) - big;
    ll me = inf;
    for(int k = 0; k <= small; k++)
    	if((sz(conv) - k) % K == 0)
    		me = min(me, k * 1LL * Y + ((sz(conv) - k) / K) * 1LL * X);
    if(me == inf) {
    	cout << -1 << endl;
    	return;
    }
    ans += me;
    conv.clear();

    for(int i = 0; i < M - 1; i++)
    {
        for(int j = idx[B[i]] + 1; j < idx[B[i + 1]]; j++)
	        conv.push_back(A[j]);
	    big = any_of(all(conv), [&](int a){ return a > max(B[i], B[i + 1]); });
	    small = sz(conv) - big;
	    me = inf;
	    for(int k = 0; k <= small; k++)
	    	if((sz(conv) - k) % K == 0)
	    		me = min(me, k * 1LL * Y + ((sz(conv) - k) / K) * 1LL * X);
	    if(me == inf) {
	    	cout << -1 << endl;
	    	return;
	    }
	    ans += me;
    	conv.clear();
    }

    for(int i = idx[B[M - 1]] + 1; i < N; i++)
    	conv.push_back(A[i]);

    big = any_of(all(conv), [&](int a){ return a > B[M - 1]; });
    small = sz(conv) - big;
    me = inf;
    for(int k = 0; k <= small; k++)
    	if((sz(conv) - k) % K == 0)
    		me = min(me, k * 1LL * Y + ((sz(conv) - k) / K) * 1LL * X);
    if(me == inf) {
    	cout << -1 << endl;
    	return;
    }
    ans += me;

    conv.clear();
	
    if(ans >= inf) ans = -1;
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
