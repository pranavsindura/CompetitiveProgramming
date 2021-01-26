#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i], sum += arr[i];
    bool ok = true;
    if(sum % n != 0)
        ok = false;

    vector<tuple<int, int, ll>> ops;
    // take out arr[i] from each and store in arr[1]
    for(int i = 2; i <= n; i++)
    {
        ll rem = arr[i] % i;
        ll add_first = (i - rem) % i;
        ops.pb(mt(1, i, add_first));
        arr[1] -= add_first;
        arr[i] += add_first;
        ops.pb(mt(i, 1, arr[i] / i));
        arr[1] += arr[i];
        arr[i] = 0;
    }

    ll mean = sum / n;
    for(int i = 2; i <= n ; i++)
    {
        ops.pb(mt(1, i, mean));
        arr[i] += mean;
        arr[1] -= mean;
        // cout << "ARRAY: ";
        // for(int i = 1; i <= n; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
    }

    if(ok)
    {
        cout << sz(ops) << endl;
        for(auto x : ops)
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    }
    else
        cout << -1 << endl;
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