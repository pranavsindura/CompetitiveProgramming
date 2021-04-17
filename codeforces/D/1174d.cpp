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
    int n, x;
    cin >> n >> x;

    if(x >= (1 << n))
    {
        vector<int> pref, arr;
        for(int i = 1; i < 1 << n; i++)
            pref.push_back(i);
        arr.push_back(pref[0]);
        for(int i = 1; i < sz(pref); i++)
            arr.push_back(pref[i - 1] ^ pref[i]);
        cout << sz(arr) << endl;
        for(int a : arr)
            cout << a << " ";
        cout << endl;
    }
    else
    {
        vector<bool> skip(1 << n);
        skip[x] = 1, skip[0] = 1;
        vector<int> pref, arr;
        for(int i = 1; i < 1 << n; i++)
            if(!skip[i]) pref.push_back(i), skip[i ^ x] = 1;
        if(pref.empty()) cout << 0 << endl;
        else
        {
            arr.push_back(pref[0]);
            for(int i = 1; i < sz(pref); i++)
                arr.push_back(pref[i - 1] ^ pref[i]);
            cout << sz(arr) << endl;
            for(int a : arr)
                cout << a << " ";
            cout << endl;
        }
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
