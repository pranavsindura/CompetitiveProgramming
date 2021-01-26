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
For each bit B we need to see if it exists in the final answer or not
that means it must have odd number of occurences in the answer
that means there must be odd number of pairs (a[i] + b[j]) that have the bit B in them
Let us try to find how many pairs have this bit B in their sum
we can reduce this to modular arithmetic
we loop on a[i] and see how many b[j] can satisfy the properties
take x = a[i] % 2^(B + 1)
take y = b[j] % 2^(B + 1)
for each x, we must find the total y's s.t.
x + y >= 2^B and x + y < 2^(B + 1)
x is fixed, we can precompute the y's and Find the range sum using BS + Prefix logic
Be careful that there will be 2 separate cases for when
x <= 2^B and x > 2^B
*/

void cp()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    ll ans = 0;
    for(int bit = 0; bit < 29; bit++)
    {
        map<int, int> rem_freq;
        for(int i = 0; i < n; i++)
            rem_freq[b[i] % (1 << (bit + 1))]++;
        vector<pi> rem;
        for(auto x : rem_freq)
            rem.pb(x);
        for(int i = 1; i < sz(rem); i++)
            rem[i].ss += rem[i - 1].ss;

        int have = 0;
        for(int i = 0; i < n; i++)
        {
            int x = a[i] % (1 << (bit + 1));
            ll me = 0;

            if(x <= (1 << bit))
            {
                // y >= 2^b - x
                int left = lower_bound(all(rem), mp((1 << bit) - x, 0)) - begin(rem);
                // y < 2^(b + 1) - x
                int right = lower_bound(all(rem), mp((1 << (bit + 1)) - x, 0)) - begin(rem);
                right--;

                if(left <= right)
                    me += rem[right].ss - (left ? rem[left - 1].ss : 0);
            }
            else
            {
                // y < 2^(b + 1) - x
                int left = (1 << (bit + 1)) - x;
                int idx = lower_bound(all(rem), mp(left, 0)) - begin(rem);
                me += rem[idx - 1].ss;
                // y >= 2^b - x + 2^(b + 1)
                int right = (1 << bit) - x + (1 << (bit + 1));
                idx = lower_bound(all(rem), mp(right, 0)) - begin(rem);
                if(idx < sz(rem))
                    me += rem.back().ss - (idx ? rem[idx - 1].ss : 0);
            }
            have = (have + me) % 2;
        }
        if(have)
            ans |= (1 << bit);
    }
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