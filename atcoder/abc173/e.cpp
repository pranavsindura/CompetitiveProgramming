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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll mul(ll a, ll b)
{
    ll res = 0;
    while(b > 0)
    {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b = b / 2;
    }
    return res % mod;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    ll res = 1;
    sort(all(arr));

    if (arr.back() <= 0 && (k & 1))
    {
        for (int i = n - 1; i >= n - k; i--)
            res = mul(res, (arr[i] + mod) % mod);
        cout << res;
        return;
    }
    int i = 0;
    int j = n - 1;
    // If we have to pick odd numbers just pick 1 +ve number
    if (k & 1)
    {
        res = (arr[j]) % mod;
        j--;
        k--;
    }
    // Else we can pick -ve numbers and +ve numbers in pairs greedily deciding which one to keep
    k /= 2;
    for (int it = 0; it < k; it++)
    {
        ll lp = arr[i] * 1LL * arr[i + 1];
        ll rp = arr[j] * 1LL * arr[j - 1];
        if (lp > rp)
        {
            res = mul(res, (lp + mod) % mod);
            i += 2;
        }
        else
        {
            res = mul(res, (rp + mod) % mod);
            j -= 2;
        }
    }
    cout << res;
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