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

vector<array<int, 2>> arr;

struct cmp1
{
    const bool operator()(const int &a, const int &b)
    {
        if(arr[a][0] != arr[b][0])
            return arr[a][0] > arr[b][0];
        else
            return a < b;
    }
};
struct cmp2
{
    const bool operator()(const int &a, const int &b)
    {
        if(arr[a][1] != arr[b][1])
            return arr[a][1] > arr[b][1];
        else
            return a < b;
    }
};

void cp()
{
    int n;
    cin >> n;
    arr.resize(n);
    for(auto &v : arr)
        cin >> v[0] >> v[1];

    set<int, cmp1> sl;
    set<int, cmp2> sr;

    for(int i = 0; i < n; i++) sl.insert(i), sr.insert(i);
    ll ans = n;
    assert(sz(sl) == n && sz(sr) == n);
    while(!sl.empty() && !sr.empty())
    {
        int x = *sl.begin();
        sl.erase(sl.begin());
        int y = *sr.begin();
        sr.erase(sr.begin());

        sl.erase(y);
        sr.erase(x);
        
        ans += max(arr[y][1], arr[x][0]);
        if(x != y)
        {
            arr.push_back({arr[y][0], arr[x][1]});
            sl.insert(sz(arr) - 1), sr.insert(sz(arr) - 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    // FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
