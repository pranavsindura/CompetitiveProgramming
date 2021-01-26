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
const int MAXN = 3e5 + 5;

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 2, 0);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    ll ans = 0;

    auto diff = [&](int i)
    {
        return max(arr[i] - arr[i + 1], 0);
    };

    auto change = [&](int i, ll val)
    {
        ans -= diff(i - 1) + diff(i);
        arr[i] = val;
        ans += diff(i - 1) + diff(i);
    };


    for(int i = 0; i <= n; i++)
        ans += diff(i);

    cout << ans << endl;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int lval = arr[l], rval = arr[r];
        change(l, rval);
        change(r, lval);
        cout << ans << endl;
    }
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