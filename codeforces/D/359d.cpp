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
const int MAXN = 3e5 + 5;

const int K = 25;
int st_min[MAXN][K + 1];
int st_gcd[MAXN][K + 1];
int lg[MAXN];

void init()
{
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

void build(vector<int> &arr)
{
    int n = sz(arr);
    for(int i = 0; i < n; i++)
        st_min[i][0] = st_gcd[i][0] = arr[i];

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
        {
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            st_gcd[i][j] = __gcd(st_gcd[i][j - 1], st_gcd[i + (1 << (j - 1))][j - 1]);
        }
}

int rmin(int L, int R)
{
    int j = lg[R - L + 1];
    return min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
}

int rgcd(int L, int R)
{
    int j = lg[R - L + 1];
    return __gcd(st_gcd[L][j], st_gcd[R - (1 << j) + 1][j]);
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    build(arr);

    int best = -1;
    vector<int> ans;

    int lo = 1, hi = n;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int cnt = 0;

        for(int i = mid - 1; i < n; i++)
        {
            int g = rgcd(i - mid + 1, i);
            int s = rmin(i - mid + 1, i);
            if(g == s) cnt++;
        }

        if(!cnt)
            hi = mid - 1;
        else
            best = mid, lo = mid + 1;
    }

    for(int i = best - 1; i < n; i++)
    {
        int g = rgcd(i - best + 1, i);
        int s = rmin(i - best + 1, i);
        if(g == s) ans.push_back(i - best + 1);
    }

    cout << sz(ans) << " " << best - 1 << endl;
    for(int x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

