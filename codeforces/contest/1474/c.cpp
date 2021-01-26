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
    vector<int> arr(2 * n);
    for(int &x : arr)
        cin >> x;
    sort(all(arr));

    int ans = -1;
    for(int i = 0; i < 2 * n - 1 && ans == -1; i++)
    {
        int S = arr.back() + arr[i];
        multiset<int> st(all(arr));
        bool ok = true;
        while(!st.empty() && ok)
        {
            int x = *st.rbegin();
            st.erase(st.lower_bound(x));
            auto it = st.lower_bound(S - x);
            if(it == st.end() || *it != S - x)
                ok = false;
            else
            {
                int y = *it;
                st.erase(it);
                S = max(x, y);
            }
        }
        if(ok) ans = arr.back() + arr[i];
    }

    if(ans == -1)
        cout << "NO\n";
    else
    {
        vector<vector<int>> ops;
        int S = ans;
        multiset<int> st(all(arr));
        bool ok = true;
        while(!st.empty() && ok)
        {
            int x = *st.rbegin();
            st.erase(st.lower_bound(x));
            auto it = st.lower_bound(S - x);
            if(it == st.end() || *it != S - x)
                ok = false;
            else
            {
                int y = *it;
                st.erase(it);
                ops.pb({x, y});
                S = max(x, y);
            }
        }

        cout << "YES\n";
        cout << ans << endl;
        for(auto v : ops)
            cout << v[0] << " " << v[1] << endl;
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

