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

/*
	< N
	K = 3
	0 0 0 12
	1 1 1 8
	2 2 2 4
	3 3 3 0

	For K = 0
	0 0

	For K < 50
	we can make N = K + 1
	and arr = 0 0 0 0 0 ... 0 N*K

	K = 4
   -1 2 3 4
	2 3 4 0
	3 4 0 1
	4 0 1 2
	0 1 2 3

   -2 3 4 5
	3 4 5 1
	4 5 1 2
	5 1 2 3
	1 2 3 4

	1 2 3 4 ... K -> K times
	for every +1 -> K times

	For K <= 50
	1 2 3 4 ... K


	For K > 50
	K = 5
   -5 1 2 3
    1 2 3 4

   -4 5 1 2
   	5 1 2 3
   	1 2 3 4


   -1 2 3
	2 3 0
	3 0 1
	0 1 2
*/

void cp()
{
    ll K;
    cin >> K;
    if(K == 0)
        cout << "2\n0 0\n";
    else if(K == 1)
        cout << "2\n0 2\n";
    else if(K <= 50)
    {
        vector<ll> arr(K);
        iota(all(arr), 1);

        cout << K << endl;
        for(int x : arr)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        ll orig = K;
        int extra = -1;
        for(int i = 0; i < 50 && extra == -1; i++)
            if((K - i) % 50 == 0)
                K = K - i, extra = i;

        vector<ll> arr(50);

        ll times = K / 50 - 1, cnt = 0;
        iota(all(arr), times + 1);

        for(int i = 49; i >= 0 && extra > 0; i--)
        	arr[i]++, extra--;

        cout << 50 << endl;
        for(ll x : arr)
            cout << x << " ";
        cout << endl;
    }
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
