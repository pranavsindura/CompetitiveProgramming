#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

/*
    n m k
	2 5 2
	if m > n + k then P = 0, as no arrangment will have enough change

	m <= n + k
	k = 0
	arrangement s.t. there are always >= 1s than 2s consecutively
	12112 right
	12122 wrong
	Similar to Bertrand's Ballot Theorem
	k > 1
	should be an extension of the same
*/

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    double p = 1;

    for(int i = 0; i <= k; i++)
        p *= double(m - i) / double(n + k + 1 - i);
    p = 1 - p;
    if(m > n + k) p = 0;
    fix(10);
    cout << p << endl;
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

