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
    for(int &x : arr)
        cin >> x;

    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++)
        L[i] = (i - 1 + n) % n, R[i] = (i + 1) % n;

    vector<int> exist(n, 1);

    queue<pi> q;
    for(int i = 1; i <= n; i++)
    {
        if(__gcd(arr[i % n], arr[i - 1]) == 1)
            q.push({i, i - 1}), i++;
    }

    vector<int> order;
    while(!q.empty())
    {
        pi u = q.front();
        q.pop();
        int p = u.ff, who = u.ss;
        if(!exist[who]) continue;
        int idx = p % n, times = p / n;
        order.push_back(idx);
        exist[idx] = 0;
        R[who] = R[idx];
        L[R[idx]] = who;

        if(__gcd(arr[who], arr[R[who]]) == 1)
            q.push({R[who], who});
    }

    cout << sz(order) << " ";
    for(int x : order)
        cout << x + 1 << " ";
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
