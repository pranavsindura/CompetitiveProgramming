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
	int n, m;
	string s;
	cin >> n >> m >> s;
	int mxx = 0, mnx = 0, mxy = 0, mny = 0;
	int x = 0, y = 0;
	for(char op: s) {
		if(op == 'L') x--;
		else if(op == 'R') x++;
		else if(op == 'U') y--;
		else y++;
		int _mxx = max(mxx, x);
		int _mnx = min(mnx, x);
		int _mxy = max(mxy, y);
		int _mny = min(mny, y);
		if(_mxx - _mnx + 1 > m) break;
		if(_mxy - _mny + 1 > n) break;
		mxx = _mxx;
		mxy = _mxy;
		mnx = _mnx;
		mny = _mny;
	}

	int Lx = 0, Rx = m - 1, Ty = 0, By = n - 1;
	Rx -= mxx;
	Lx -= mnx;
	Ty -= mny;
	By -= mxy;
	assert(Lx <= Rx);
	assert(Ty <= By);
	cout << Ty + 1 << " " << Lx + 1 << endl;
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
