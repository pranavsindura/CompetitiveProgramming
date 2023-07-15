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
	int n;
	cin >> n;
	vector<array<int, 2>> dots(n);
	for(int i = 0; i < n; i++)
		cin >> dots[i][0];
	for(int i = 0; i < n; i++)
		cin >> dots[i][1];

	sort(all(dots));
	ll ans = 0;
	int A = 1, B = 1;
	for(int i = 0; i < n; i++) {
		int x = dots[i][0], y = dots[i][1];
		int top_left_steps = y - B;
		int nx = x - top_left_steps, ny = y - top_left_steps;

		if((nx + ny) % 2) {
			// go
			x = nx, y = ny;
		} else if(!(nx == A && ny == B)) {
			// go top right once then go top left
			if((x + y) % 2 == 0) ans++;
			x = nx - 1, y = ny;
		} else {
			// go
			ans += top_left_steps;
			x = nx, y = ny;
		}

		int top_right_steps = x - A;
		if((A + B) % 2) ans += (top_right_steps + 1) / 2;
		else ans += top_right_steps / 2;

		A = dots[i][0], B = dots[i][1];
	}

	cout << ans << endl;
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
