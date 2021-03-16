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
const int MAXN = 1e5 + 5;

const int K = 18;
int st[MAXN][K + 1];
int lg2[MAXN];

void build(vector<int> &arr)
{
    lg2[1] = 0;
    for(int i = 2; i < MAXN; i++)
        lg2[i] = lg2[i / 2] + 1;

    for(int i = 0; i < sz(arr); i++)
        st[i][0] = arr[i];
    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << (j - 1)) < sz(arr); i++)
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R)
{
    int j = lg2[R - L + 1];
    return __gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

void cp()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    build(arr);
    map<int, ll> freq;

    for(int i = 0; i < n; i++)
    {
        int l = i;
        while(l < n)
        {
            int g = query(i, l);
            int r = l;
            int lo = l, hi = n - 1;
            while(lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                int res = query(i, mid);
                if(res == g) r = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            freq[g] += r - l + 1;
            l = r + 1;
        }
    }

    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << freq[x] << endl;
    }
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
