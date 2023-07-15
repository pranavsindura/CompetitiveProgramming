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

void cp()
{
	ll x0, n, offset;
	cin >> x0 >> n;
	if(n == 0){
		cout << x0 << endl;
		return;
	}
	ll rem = n % 4;
	ll mul = (n + 3) / 4;
	if(abs(x0) % 2 == 0)
	{
		if(rem == 0) offset = 0;
		else if(rem == 1) offset = -4 * mul + 3;
		else if(rem == 2) offset = 1;
		else offset = 4 * mul;
	}
	else 
	{
		if(rem == 0) offset = 1;
		else if(rem == 1) offset = 4 * mul - 2;
		else if(rem == 2) offset = 0;
		else offset = -4 * mul + 1;
		offset--;
	}

	cout << x0 + offset << endl;
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
