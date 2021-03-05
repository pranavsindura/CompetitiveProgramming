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
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    vector<ll> jumps(n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(jumps[i] > 0)
        {
            ll e = min(n - 1LL, i + arr[i]);
            ll rem = i + arr[i] - e;
            rem = min(rem, jumps[i]);
            jumps[i] -= rem;
            arr[i] -= rem;
            arr[i] = max(1LL, arr[i]);
        }

        while(jumps[i] > 0 && arr[i] > 1)
        {
            if(i + arr[i] < n) jumps[i + arr[i]]++;
            arr[i]--;
            jumps[i]--;
        }

        if(i + 1 < n) jumps[i + 1] += jumps[i];

        if(i < n - 1)
        {
            ll take = max(0LL, arr[i] - (n - i - 1));
            ans += take;
            arr[i] -= take;
            while(arr[i] > 1)
            {
                if(i + arr[i] < n)
                    jumps[i + arr[i]]++;
                arr[i]--;
                ans++;
            }
        }
        else
            ans += arr[i] - 1;
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
