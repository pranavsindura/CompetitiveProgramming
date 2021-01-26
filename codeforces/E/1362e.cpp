#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll fpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % m * x % m) % m;
        x = (x % m * x % m) % m;
        y >>= 1;
    }
    return res;
}

vector<int> arr;

void cp()
{
    int n, p;
    cin >> n >> p;

    arr.resize(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // If sum is zero, add p^k
    // if sum is +ve, remove p^k
    sort(allr(arr));

    ll sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0;
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9, mod3 = 1e9 + 21;
    // Hashing values % all primes
    for(int i = 0; i < n; i++)
    {
        if(sum1 == 0 && sum2 == 0 && sum3 == 0)
        {
            sum1 = (sum1 + fpow(p, arr[i], mod1)) % mod1;
            sum2 = (sum2 + fpow(p, arr[i], mod2)) % mod2;
            sum3 = (sum3 + fpow(p, arr[i], mod3)) % mod3;
        }
        else
        {
            sum1 = (sum1 - fpow(p, arr[i], mod1) + mod1) % mod1;
            sum2 = (sum2 - fpow(p, arr[i], mod2) + mod2) % mod2;
            sum3 = (sum3 - fpow(p, arr[i], mod3) + mod3) % mod3;
        }
    }
    cout << sum1 << endl;
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