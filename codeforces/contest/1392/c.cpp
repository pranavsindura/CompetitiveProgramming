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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<vector<int>> range;
    range.pb(vector<int>());
    range[0].pb(arr[0]);
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= range.back().back())
            range.back().pb(arr[i]);
        else
            range.pb(vector<int>()), range.back().pb(arr[i]);
    }
    ll ans = 0;
    for(int i = sz(range) - 1; i > 0; i--)
    {
        int to = range[i - 1].back();
        int need = to - range[i].front();
        ans += need;
        // range[i].back() = max(range[i].back(), to);
    }
    cout << ans << endl;
}

int main()
{
    FASTIO;
    // time_t t1, t2;
    // t1 = clock();
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    // t2 = clock();
    // cerr << endl << "time taken: " << (long double) (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}