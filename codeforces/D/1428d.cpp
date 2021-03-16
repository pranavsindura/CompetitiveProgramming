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

    vector<vector<int>> target;
    vector<deque<int>> pos(4);
    vector<int> at(n);

    bool ok = true;
    int H = n - 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == 1) target.push_back({H, i}), at[i] = H, H--;
        else if(arr[i] == 2)
        {
            // need a 1
            if(pos[1].empty()) ok = false;
            else
            {
                int x = pos[1].back();
                pos[1].pop_back();
                target.push_back({at[x], i});
                at[i] = at[x];
            }
        }
        else if(arr[i] == 3)
        {
            // need a 3 or a 2 or a 1
            if(!pos[3].empty())
            {
                int x = pos[3].back();
                pos[3].pop_back();
                target.push_back({H, x});
                target.push_back({H, i});
                at[i] = H;
                H--;
            }
            else if(!pos[2].empty())
            {
                int x = pos[2].back();
                pos[2].pop_back();
                target.push_back({H, x});
                target.push_back({H, i});
                at[i] = H;
                H--;
            }
            else if(!pos[1].empty())
            {
                int x = pos[1].back();
                pos[1].pop_back();
                target.push_back({H, x});
                target.push_back({H, i});
                at[i] = H;
                H--;
            }
            else
                ok = false;
        }
        pos[arr[i]].push_front(i);
    }

    if(ok)
    {
        cout << sz(target) << endl;
        for(auto v : target)
            cout << v[0] + 1 << " " << v[1] + 1 << endl;
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
