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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

ll solve(vector<vector<int>> arr, ll S)
{
    // (slices, A, B, rem)
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        arr[i].push_back(arr[i][0]);

    ll total_slices = 0;
    for(int i = 0; i < n; i++)
        total_slices += arr[i][0];

    ll pizza = (total_slices + S - 1) / S;

    ll G = 0;
    for(int i = 0; i < n; i++)
        if(arr[i][1] > arr[i][2])
            G += arr[i][0];

    ll needA = (G + S - 1) / S;
    ll needB = pizza - needA;
    assert(needA >= 0 && needB >= 0);

    ll sliceA = needA * S;
    ll sliceB = needB * S;

    ll ans = 0;
    // satisfy all A > B
    for(int i = 0; i < n; i++)
        if(arr[i][1] > arr[i][2])
            ans += arr[i][0] * 1LL * arr[i][1], arr[i][3] = 0, sliceA -= arr[i][0];
    // sort by B, satisfy largest happiness first
    sort(all(arr), [&](vector<int> a, vector<int> b)
    {
    	return a[2] - a[1] > b[2] - b[1];
    });
    for(int i = 0; i < n; i++)
    {
        int take = min(sliceB, arr[i][3] * 1LL);
        sliceB -= take, arr[i][3] -= take;
        ans += take * 1LL * arr[i][2];
    }
    // satisfy remaining with A
    for(int i = 0; i < n; i++)
    {
        int take = min(sliceA, arr[i][3] * 1LL);
        sliceA -= take, arr[i][3] -= take;
        ans += take * 1LL * arr[i][1];
    }
    return ans;
}

void cp()
{
    int n, S;
    cin >> n >> S;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];

    ll A = solve(arr, S);
    for(int i = 0; i < n; i++)
        swap(arr[i][1], arr[i][2]);
    ll B = solve(arr, S);

    cout << max(A, B) << endl;
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
