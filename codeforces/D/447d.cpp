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
const ll inf = 1e15;
const int MAXN = 1e3 + 5;

int arr[MAXN][MAXN];

void cp()
{
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<ll> r(k + 1), c(k + 1);
    priority_queue<int> rpq, cpq;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < m; j++)
            sum += arr[i][j];
        rpq.push(sum);
    }
    for(int j = 0; j < m; j++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i][j];
        cpq.push(sum);
    }
    for(int i = 1; i <= k; i++)
    {
        int sum = rpq.top();
        rpq.pop();
        r[i] = r[i - 1] + sum;
        sum -= m * p;
        rpq.push(sum);
    }
    for(int i = 1; i <= k; i++)
    {
        int sum = cpq.top();
        cpq.pop();
        c[i] = c[i - 1] + sum;
        sum -= n * p;
        cpq.push(sum);
    }
    ll ans = LLONG_MIN;
    for(int i = 0; i <= k; i++)
        ans = max(ans, r[i] + c[k - i] - i * 1LL * (k - i) * p);
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

