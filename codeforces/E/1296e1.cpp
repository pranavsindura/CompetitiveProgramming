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
    string s;
    cin >> n >> s;

    string t = s;
    sort(all(t));

    vector<pair<char, int>> arr;
    for(int i = 0; i < n; i++) arr.push_back({s[i], i});

    bool ok = true;
    string colour(n, '0');
    vector<int> to(n, -1);
    for(int i = 0; i < n; i++)
    {
        int idx = -1;
        for(int j = i; j < n && idx == -1; j++)
            if(arr[j].first == t[i])
                idx = j;
        if(idx == i) continue;
        assert(~idx);
        to[arr[idx].second] = i;
        bool one = 0;
        for(int j = idx; j >= i; j--) one |= colour[arr[j].second] == '1';
        if(one) ok = false;
        colour[arr[idx].second] = '1';
        auto save = arr[idx];
        for(int j = idx - 1; j >= i; j--) swap(arr[j], arr[j + 1]);
        arr[i] = save;

        string here, ones;
        for(auto x : arr) here += x.first, ones += colour[x.second];
    }

    int last = -1;
    for(int x : to) if(~x) ok &= x > last, last = x;

    cout << (ok ? "YES\n" + colour : "NO") << endl;
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

