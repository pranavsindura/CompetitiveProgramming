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
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        arr[i] = {l, r, i};
    }

    vector<int> L(n), R(n);

    sort(all(arr), [&](vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int l = arr[i][0], r = arr[i][1];
        while(!pq.empty() && pq.top() < l) cnt++, pq.pop();
        L[arr[i][2]] = cnt;
        pq.push(r);
    }

    sort(all(arr), [&](vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    });

    priority_queue<int> pq2;
    cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int l = arr[i][0], r = arr[i][1];
        while(!pq2.empty() && pq2.top() > r) cnt++, pq2.pop();
        R[arr[i][2]] = cnt;
        pq2.push(l);
    }
    int ans = n - 1;
    for(int i = 0; i < n; i++)
        ans = min(ans, L[i] + R[i]);
    cout << ans << endl;
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

