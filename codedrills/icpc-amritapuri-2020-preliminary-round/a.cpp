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
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        arr[i].resize(m);
        for(int &x : arr[i])
            cin >> x;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        vector<int> grp;
        int cnt = 1;
        for(int j = 1; j < sz(arr[i]); j++)
            if(arr[i][j] > arr[i][j - 1])
                cnt++;
            else
                grp.push_back(cnt), cnt = 1;
        grp.push_back(cnt);
        total += accumulate(all(grp), 0) - *max_element(all(grp));
        for(int x : grp)
            pq.push(x);
    }

    while(sz(pq) > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        total += a + b;
        pq.push(a + b);
    }

    cout << total << endl;
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
