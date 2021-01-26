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
    ll m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<ll> one, two;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
            one.push_back(arr[i]);
        else
            two.push_back(arr[i]);
    }

    sort(allr(one));
    sort(allr(two));

    for(int i = 1; i < sz(two); i++) two[i] += two[i - 1];

    int ans = inf;

    auto it = lower_bound(all(two), m);
    if(it != two.end())
    {
        int idx = it - two.begin();
        ans = min(ans, (idx + 1) * 2);
    }

    ll sum = 0;
    for(int i = 0; i < sz(one); i++)
    {
        sum += one[i];
        ll need = m - sum;
        if(need > 0)
        {
            it = lower_bound(all(two), m - sum);
            if(it == two.end()) continue;
            int idx = it - two.begin();
            ans = min(ans, i + 1 + (idx + 1) * 2);
        }
        else
            ans = min(ans, i + 1);
    }

    if(ans == inf) ans = -1;
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

