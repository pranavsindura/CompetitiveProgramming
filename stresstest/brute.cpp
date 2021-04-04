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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 1; i <= n; i++)
        cin >> arr[i - 1];
    bool done = false;
    int cnt = 0;
    while(!done)
    {
        done = true;
        vector<int> res;
        int l = 0;
        while(l < n)
        {
            int r = l;
            while(r + 1 < n && arr[r + 1] < arr[r]) r++;
            if(l < r) done = false;
            res.push_back(arr[l]);
            l = r + 1;
        }
        n = sz(res);
        arr = res;
        cnt += !done;
    }

    cout << cnt << endl;
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
