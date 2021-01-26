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
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;
    vector<pi> ops;
    // 00 11
    int cnt = 0;
    cnt += (arr[0][1] == '1');
    cnt += (arr[1][0] == '1');
    cnt += (arr[n - 1][n - 2] == '0');
    cnt += (arr[n - 2][n - 1] == '0');
    if(cnt <= 2)
    {
        // do it
        if(arr[0][1] == '1')
            ops.pb({0, 1});
        if(arr[1][0] == '1')
            ops.pb({1, 0});
        if(arr[n - 1][n - 2] == '0')
            ops.pb({n - 1, n - 2});
        if(arr[n - 2][n - 1] == '0')
            ops.pb({n - 2, n - 1});
    }
    else
    {
        // 11 00
        if(arr[0][1] == '0')
            ops.pb({0, 1});
        if(arr[1][0] == '0')
            ops.pb({1, 0});
        if(arr[n - 1][n - 2] == '1')
            ops.pb({n - 1, n - 2});
        if(arr[n - 2][n - 1] == '1')
            ops.pb({n - 2, n - 1});
    }

    cout << sz(ops) << endl;
    for(pi x : ops)
        cout << x.ff + 1 << " " << x.ss + 1 << endl;
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