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
    int t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    set<int> left, right;
    function<void(int, int, int)> subset = [&](int i, int j, int sum)
    {
        if(i == j)
        {
            if(i == n)
                right.insert(sum);
            else
                left.insert(sum);
        }
        else
        {
            subset(i + 1, j, sum);
            if(sum + arr[i] <= t)
                subset(i + 1, j, sum + arr[i]);
        }
    };
    subset(0, n / 2, 0);
    subset(n / 2, n, 0);
    int ans = 0;
    for(int x : left)
    {
        int rem = t - x;
        auto it = right.upper_bound(rem);
        if(it != begin(right)) it--;
        if(x + *it <= t)
            ans = max(ans, x + *it);
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