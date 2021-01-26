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
    int n, R, C;
    cin >> n >> R >> C;
    vector<string> arr(n);
    for(auto &x : arr)
        cin >> x;

    vector<vector<int>> lift(22, vector<int>(n + 1));

    for(int i = 0; i <= 21; i++)
        for(int j = 0; j <= n; j++)
            lift[i][j] = j;

    int j = -1, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(j < i)
        {
            j = i, cnt = sz(arr[i]);
            if(cnt > C)
                continue;
        }

        while(j + 1 < n && cnt + sz(arr[j + 1]) + (j - i + 1) <= C)
            j++, cnt += sz(arr[j]);

        lift[0][i] = j + 1;
        cnt -= sz(arr[i]);
    }

    for(int i = 1; i <= 21; i++)
        for(int j = 0; j < n; j++)
            lift[i][j] = lift[i - 1][lift[i - 1][j]];

    int idx = -1, best = -1;

    for(int i = 0; i < n; i++)
    {
        if(sz(arr[i]) > C) continue;
        // Find the Rth descendent
        int k = i;
        for(j = 21; j >= 0; j--)
        {
            if((R >> j) & 1)
                k = lift[j][k];
        }

        int have = k - i;
        if(have > best)
            best = have, idx = i;
    }


    // Improve this
    // Find a path of length K with maximum weight

    // vector<bool> vis(n);
    // for(int i = 0; i < n; i++)
    // {
    //     if(vis[i] || sz(arr[i]) > C) continue;
    //     vector<int> pos, words;
    //     int total = 0;
    //     j = i;
    //     while(j < n)
    //         vis[j] = 1, pos.pb(j), words.pb(units[j]), j = adj[j];
    //     for(j = 1; j < sz(words); j++)
    //         words[j] += words[j - 1];
    //     for(j = 0; j < sz(words); j++)
    //     {
    //         int k = min(sz(words) - 1, j + R - 1);
    //         int have = words[k] - (j ? words[j - 1] : 0);
    //         if(have > best)
    //             best = have, idx = pos[j];
    //     }

    //     for(int x : pos)
    //         cout << x << " ";
    //     cout << endl;
    // }

    // cout << idx << " " << best << endl;

    if(best == -1) return; // empty banner should the solution

    j = idx;
    cnt = 0;
    string ans;
    while(j < n && best > 0)
    {
        if(sz(ans) + (!ans.empty()) + sz(arr[j]) <= C)
        {
            if(!ans.empty()) ans += ' ';
            ans += arr[j];
        }
        else
            cout << ans << endl, ans = arr[j];
        j++;
        best--;
    }
    if(!ans.empty() && best >= 0)
        cout << ans << endl;
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

