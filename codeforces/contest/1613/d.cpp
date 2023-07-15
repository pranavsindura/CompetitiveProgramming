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
const ll mod = 998244353;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

int brute(vector<int> &A)
{
	int n = sz(A);
	int cnt = 0;
	for(int msk = 1; msk < (1 << n); msk++)
	{
		vector<int> avail(n + 1);
		int mex = 0;
		bool ok = true;
		for(int i = 0; i < n; i++)
			if((msk >> i) & 1)
			{
				avail[A[i]]++;
				while(mex <= n && avail[mex]) mex++;
				ok &= abs(A[i] - mex) <= 1;
			}
		cnt += ok;
	}

	return cnt;
}

void cp()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int &x: A)
		cin >> x;

	vector<ll> ans(n), inc(n + 1), broken(n + 1);

	for(int i = 0; i < n; i++)
	{
		if(A[i] == 0) ans[i] = (ans[i] + 1) % mod; // starting at itself
		ans[i] = (ans[i] + inc[A[i]]) % mod; // inc where last number was A[i]
		if(A[i] > 0) ans[i] = (ans[i] + inc[A[i] - 1]) % mod; // inc where last number was A[i] - 1

		if(A[i] == 1) ans[i] = (ans[i] + 1) % mod; // broken with no 0
		if(A[i] > 1) ans[i] = (ans[i] + inc[A[i] - 2]) % mod; // break the seq
		if(A[i] + 2 <= n) ans[i] = (ans[i] + broken[A[i] + 2]) % mod; // broken where last number as A[i] + 2
		ans[i] = (ans[i] + broken[A[i]]) % mod; // broken where last number as A[i]

		inc[A[i]] = (2 * inc[A[i]]) % mod; // the one and where the last number was A[i];
		if(A[i] == 0) inc[A[i]] = (inc[A[i]] + 1) % mod; // the one which started at itself
		if(A[i] > 0) inc[A[i]] = (inc[A[i]] + inc[A[i] - 1]) % mod; // the ones which are inc and last number was A[i] - 1

		broken[A[i]] = (2 * broken[A[i]]) % mod; // broken can now include A[i]
		if(A[i] > 1) broken[A[i]] = (broken[A[i]] + inc[A[i] - 2]) % mod; // newly broken seq
		if(A[i] + 2 <= n) broken[A[i] + 2]  = (2 * broken[A[i] + 2]) % mod; // broken where last number as A[i] + 2
		if(A[i] == 1) broken[A[i]] = (broken[A[i]] + 1) % mod; // broken with no 0
	}

	ll sum = 0;
	for(ll x: ans)
		sum = (sum + x) % mod;
	cout << sum << endl;
	// cout << brute(A) << endl;
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
