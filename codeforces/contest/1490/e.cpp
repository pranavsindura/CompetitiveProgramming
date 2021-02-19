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

    vector<pi> pos;
    for(int i = 0; i < n; i++)
    	pos.push_back({arr[i], i});

    sort(all(arr));
    sort(all(pos));

    vector<ll> pref(n);
    partial_sum(all(arr), pref.begin());

    vector<int> win(n);
    win[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        ll p = pref[i];
        if(p >= arr[i + 1] && win[i + 1]) win[i] = 1;
    }

    int m = 0;
    vector<int> can;
    for(int i = 0; i < n; i++)
        if(win[i])
            m++, can.push_back(pos[i].second);
    sort(all(can));
    
    cout << m << endl;
    for(int x : can)
        cout << x + 1 << " ";
    cout << endl;
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
