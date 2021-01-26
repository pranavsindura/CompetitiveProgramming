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
    map<int, int> freq;
    map<pair<ll, ll>, int> vis;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, freq[x]++;

    function<int(ll, ll)> dfs = [&](ll a, ll b)
    {
        int me = 1;
        if(freq.count(a + b) && freq[a + b] > 0)
        {
            freq[a + b]--;
            me += dfs(b, a + b);
            freq[a + b]++;
        }
        return me;
    };
    int ans = 2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || vis[mp(arr[i], arr[j])]) continue;
            freq[arr[i]]--;
            freq[arr[j]]--;
            vis[mp(arr[i], arr[j])] = 1;
            ans = max(ans, 1 + dfs(arr[i], arr[j]));
            freq[arr[i]]++;
            freq[arr[j]]++;
        }
    }
    cout << ans << endl;
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

