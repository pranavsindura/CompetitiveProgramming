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
const int MAXN = 1e6 + 5;

vector<vector<int>> pos(MAXN);

void cp()
{
    int n;
    cin >> n;
    set<int> dis;
    for(int i = 0, x; i < n; i++)
        cin >> x, pos[x].pb(i), dis.insert(x);
    vector<int> arr(all(dis));

    int ans = 0;

    for(int i = 0; i < sz(arr); i++)
        for(int j = 0; j < sz(arr); j++)
        {
            if(i == j) continue;
            int l = 0, r = 0, turn = 1, me = 1;
            while(true)
            {
                if(turn) // pick r
                {
                    while(r < sz(pos[arr[j]]) && pos[arr[j]][r] < pos[arr[i]][l])
                        r++;
                    if(r >= sz(pos[arr[j]])) break;
                }
                else // pick l
                {
                    while(l < sz(pos[arr[i]]) && pos[arr[i]][l] < pos[arr[j]][r])
                        l++;
                    if(l >= sz(pos[arr[i]])) break;
                }
                me++;
                turn ^= 1;
            }
            ans = max(ans, me);
        }
    for(int i = 1; i < MAXN; i++) ans = max(ans, sz(pos[i]));
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

