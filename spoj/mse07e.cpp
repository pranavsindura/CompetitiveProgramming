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

array<ll, 3> get(string s)
{
    stringstream ss(s);
    ll l, r, k;
    ss >> l >> r >> k;
    return {l, r, k};
}

string clean(string &s)
{
    while(!s.empty() && !isdigit(s.back()))
        s.pop_back();
    return s;
}

void cp()
{
    string s;
    while(getline(cin, s))
    {
        vector<array<ll, 3>> arr;

        s = clean(s);
        if(s.empty()) continue;
        arr.push_back(get(s));
        while(getline(cin, s) && !(clean(s)).empty())
            arr.push_back(get(s));

        int n = sz(arr);

        ll ans = -1;
        ll lo = 0, hi = 1e10;
        while(lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            ll sum = 0;
            for(int i = 0; i < n; i++)
            {
                ll l = arr[i][0], r = min(mid, arr[i][1]), k = arr[i][2];
                ll step = (r - l) / k + 1;
                step = max(step, 0LL);
                sum += step;
            }
            if(sum & 1)
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        if(~ans)
        {
            int times = 0;
            for(int i = 0; i < n; i++)
            {
                ll l = arr[i][0], r = arr[i][1], k = arr[i][2];
                if(l <= ans && ans <= r && l % k == ans % k) times++;
            }
            cout << ans << " " << times << endl;
        }
        else
            cout << "no corruption\n";
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

