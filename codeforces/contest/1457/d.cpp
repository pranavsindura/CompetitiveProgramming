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
	If two same -> 1
	All distinct and strictly increasing
	a < b < c < d
	if we xor b and c, max value of b^c is bound by the MSB in c
	it can be 011111 at max if MSB of c is at 5
	For a < b^c < d to still hold
	d must be the next power of 2
	If we extend this to n numbers,
	This means that if the answer is not possible in 1 move
	Then the size of array must be <= 30 (?)

	000001
	000010
	000100
	001000

	but we can put more numbers in between

	000001
	000010
	000011
	000100
	001000
	001100
	
	at most 2, then size of array should be <= 60

	Then we can brute force it
	pref[i] ^ pref[x - 1] > pref[y] ^ pref[i]
	minimise i - (x - 1) - 1 + y - i - 1 = -x + y - 1
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    int ans = inf;
    for(int i = 0; i < n - 1; i++)
    {
        int v = arr[i] ^ arr[i + 1];
        if(i - 1 >= 0 && arr[i - 1] > v)
            ans = 1;
        if(i + 2 < n && arr[i + 2] < v)
            ans = 1;
    }
    if(ans != 1)
    {
        assert(n <= 60);
        for(int i = 1; i < n; i++)
            arr[i] ^= arr[i - 1];
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                for(int k = i + 1; k < n; k++)
                {
                    int u = arr[i] ^ (j ? arr[j - 1] : 0);
                    int v = arr[k] ^ arr[i];
                    if(u > v)
                    {
                        ans = min(ans, k - j - 1);
                    }
                }
            }
        }
    }
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

