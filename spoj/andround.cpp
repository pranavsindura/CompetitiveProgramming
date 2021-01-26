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

void cp()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(30));
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for(int b = 0; b < 30; b++)
            arr[i][b] = (x >> b) & 1;
    }

    for(int i = 1; i < n; i++)
        for(int j = 0; j < 30; j++)
            arr[i][j] += arr[i - 1][j];

    auto val = [&](int l, int r)
    {
        if(l > r) return (1 << 30) - 1;
        int num = 0;
        for(int b = 0; b < 30; b++)
        {
            int sum = arr[r][b] - (l ? arr[l - 1][b] : 0);
            if(sum == r - l + 1)
                num |= 1 << b;
        }
        return num;
    };

    vector<int> ans(n);
    int mul = k > n;
    k %= n;
    for(int i = 0; i < n; i++)
    {
        ans[i] = (1 << 30) - 1;

        int take = min(k, i);
        int wrap = k - take;
        ans[i] &= val(i - take, i); // Left
        ans[i] &= val(n - wrap, n - 1); // Wrap

        take = min(k, n - i - 1);
        wrap = k - take;
        ans[i] &= val(i, i + take); // Right
        ans[i] &= val(0, wrap - 1); // Wrap

        if(mul) ans[i] &= val(0, n - 1);
    }

    for(int x : ans)
        cout << x << " ";
    cout << endl;
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

