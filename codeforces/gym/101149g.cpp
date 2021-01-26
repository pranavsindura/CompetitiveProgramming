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
    int n, m;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y, i};
    }
    cin >> m;
    vector<vector<int>> axe(m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        axe[i] = {x, y, i};
    }
    sort(all(arr)), sort(all(axe));
    set<vector<int>> st;
    bool ok = true;
    vector<int> ans(n, -1);
    while(!arr.empty() && ok)
    {
        auto u = arr.back();
        arr.pop_back();
        while(!axe.empty() && axe.back()[0] >= u[0])
            st.insert({axe.back()[1], axe.back()[0], axe.back()[2]}), axe.pop_back();
        auto it = st.lower_bound({u[1], u[0], -1});
        if(it == st.end())
        {
            ok = false;
            continue;
        }
        ans[u[2]] = (*it)[2];
        st.erase(it);
    }

    if(ok)
    {
        for(int x : ans)
            cout << x + 1 << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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

