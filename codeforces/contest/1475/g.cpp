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
const int MAXN = 2e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> cnt(MAXN);
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, cnt[x]++;
    vector<int> dp(MAXN);
    for(int i = 1; i < MAXN; i++)
    {
        dp[i] += cnt[i];
        for(int j = 2 * i; j < MAXN; j += i)
            dp[j] = max(dp[j], dp[i]);
    }
    int ans = n - *max_element(all(dp));
    cout << ans << endl;
}

// void cp()
// {
//     int n;
//     cin >> n;
//     vector<int> cnt(MAXN);
//     vector<int> arr(n);
//     for(int &x : arr)
//         cin >> x, cnt[x]++;

//     set<int> st(all(arr));
//     vector<int> dis(all(st));
//     vector<int> idx(MAXN, -1);
//     for(int i = 0; i < sz(dis); i++)
//         idx[dis[i]] = i;

//     vector<int> dp(sz(dis));

//     for(int i = 0; i < sz(dis); i++)
//     {
//         dp[i] = max(dp[i], cnt[dis[i]]);
//         for(int j = 1; j <= sqrt(dis[i]); j++)
//         {
//             if(dis[i] % j) continue;
//             int p = j;
//             if(~idx[p] && p != dis[i])
//             {
//                 dp[i] = max(dp[i], dp[idx[p]] + cnt[dis[i]]);
//             }
//             int q = dis[i] / j;
//             if(~idx[q] && q != dis[i])
//             {
//                 dp[i] = max(dp[i], dp[idx[q]] + cnt[dis[i]]);
//             }
//         }
//     }

//     int ans = n - *max_element(all(dp));
//     cout << ans << endl;
// }

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

