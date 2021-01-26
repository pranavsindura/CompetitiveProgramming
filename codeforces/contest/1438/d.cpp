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
	For each bit there must be either even number of 0s or even number of 1s
	because we cannot make that bit 0 for all of them or 1 for all of them if both of them are odd

	1,2,3...a,b,c... are just symbols

	If we pick a b b as the numbers then
	a b b -> a a a
	we can make these equal

	For odd n
	1 2 3 4 5 6 7
	we can take 3 numbers and make them equal, then skip 2 at a time to make pairs of numbers equal
	a a a 4 5 6 7
	a a b b b 6 7
	a a b b c c c

	Then pick one number as c and pick pairs of numbers to make them equal to c
	a a b b c c c
	a a b b c c c
	a a c c c c c 
	c c c c c c c

	For even n
	The observation is, since n is even and a each bit has even 0s and even 1s
	the xor of all the numbers is zero
	a1 ^ a2 ^ a3 ^a4 ... ^ an = 0
	a1 ^ a2 ^ a3 ^a4 ... ^ a(n-1) = a^n

	If we do the same thing as for odd n

	1 2 3 4 5 6 7 8
	a a a 4 5 6 7 8
	a a b b b 6 7 8
	a a b b c c c 8

	Here c = 1^2^3^4^5^6^7 = 8

	This means that the array has become
	a a b b 8 8 8 8
	If we ignore the last number then wa can proceed as n is odd
	a a b b 8 8 8 (8)
	a a b b 8 8 8 (8)
	a a 8 8 8 8 8 (8)
	8 8 8 8 8 8 8 (8)
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    vector<vector<int>> ops;

    bool ok = true;
    for(int b = 0; b < 30; b++)
    {
        vector<int> cnt(2);
        for(int i = 0; i < n; i++)
            cnt[(arr[i] >> b) & 1]++;
        if(cnt[0] % 2 && cnt[1] % 2)
            ok = false;
    }

    for(int i = 0; i + 2 < n; i += 2)
    {
        int v = arr[i] ^ arr[i + 1] ^ arr[i + 2];
        arr[i] = arr[i + 1] = arr[i + 2] = v;
        ops.pb({i, i + 1, i + 2});
    }

    // ignore last if even
    if(n % 2 == 0) n--;

    for(int i = n - 2; i - 1 >= 0; i -= 2)
    {
        int v = arr[n - 1] ^ arr[i] ^ arr[i - 1];
        arr[n - 1] = arr[i] = arr[i - 1] = v;
        ops.pb({n - 1, i, i - 1});
    }

    if(ok)
    {
        cout << "YES\n";
        cout << sz(ops) << endl;
        for(auto v : ops)
            cout << v[0] + 1 << " " << v[1] + 1 << " " << v[2] + 1 << endl;
        assert(sz(ops) <= n);
    }
    else
        cout << "NO\n";
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