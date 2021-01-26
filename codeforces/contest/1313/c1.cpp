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

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    int idx = -1;
    ll best = 0;
    for(int i = 0; i < n; i++)
    {
        // max height at i
        ll me = arr[i];
        ll last = arr[i];
        for(int j = i + 1; j < n; j++)
            last = min(last, arr[j]), me += last;
        last = arr[i];
        for(int j = i - 1; j >= 0; j--)
            last = min(last, arr[j]), me += last;
        if(me > best)
            best = me, idx = i;
    }
    vector<ll> ans(n);
    ans[idx] = arr[idx];
    ll last = arr[idx];
    for(int j = idx + 1; j < n; j++)
        last = min(last, arr[j]), ans[j] = last;
    last = arr[idx];
    for(int j = idx - 1; j >= 0; j--)
        last = min(last, arr[j]), ans[j] = last;
    for(ll x : ans)
        cout << x << " ";
    cout << endl;
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

