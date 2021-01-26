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
    vector<pair<ll, ll>> arr(n);
    for(auto &x : arr)
        cin >> x.ff >> x.ss;

    arr.pb({1e15, arr.back().ss});
    
    vector<int> at(n + 1);

    ll pos = 0;
    ll dir = 0;
    ll target = 0;

    for(int i = 0; i < n + 1; i++)
    {
        ll diff = min(target, arr[i].ff) - (i ? arr[i - 1].ff : 0);
        ll cur = pos + dir * diff;
        pos = cur;
        at[i] = pos;
        if(target <= arr[i].ff) // new move
        {
            if(arr[i].ss > pos) dir = 1;
            else if(arr[i].ss < pos) dir = -1;
            else dir = 0;
            target = arr[i].ff + abs(arr[i].ss - pos);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += arr[i].ss >= min(at[i], at[i + 1]) && arr[i].ss <= max(at[i], at[i + 1]);

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

