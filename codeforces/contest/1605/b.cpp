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
    string s;
    cin >> n >> s;
    vector<vector<int>> ops;
    while(!is_sorted(all(s)))
    {
        vector<int> ones, zeros;
        int l = 0, r = n - 1;
        while(l < n)
        {
            while(s[l] == '0' && l < n) l++;
            if(l >= n) break;
            while(s[r] == '1' && r > l) r--;
            if(r <= l) break;
            ones.push_back(l);
            zeros.push_back(r);
            l++, r--;
        }

        for(int i = 0; i < sz(ones); i++)
            swap(s[ones[i]], s[zeros[i]]);

        reverse(all(zeros));
        ops.push_back({});
        for(int x : ones) ops.back().push_back(x);
        for(int x : zeros) ops.back().push_back(x);
    }

    cout << sz(ops) << endl;
    if(!ops.empty())
    {
        for(auto v : ops)
        {
            cout << sz(v) << " ";
            for(int x : v) cout << x + 1 << " ";
            cout << endl;
        }
    }
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
