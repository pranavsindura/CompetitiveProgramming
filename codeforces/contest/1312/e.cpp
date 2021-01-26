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

int n;
vector<int> arr;

bool vis[505][505];
tuple<int, int> dp[505][505];// (element, len), element -> which single element if possible, len -> smallest possible length of the partition [i, j]

tuple<int, int> solve(int i, int j)
{

    if(vis[i][j]) return dp[i][j];

    vis[i][j] = 1;

    if(i == j) return dp[i][j] = make_tuple(arr[i], 1);

    int ele = -1, len = j - i + 1;

    for(int k = i; k < j; k++)
    {
        tuple<int, int> L = solve(i, k);
        tuple<int, int> R = solve(k + 1, j);
        if(get<1>(L) == 1 && get<1>(R) == 1) // both can be reduced to single elements
        {
            int l = get<0>(L), r = get<0>(R);
            if(l == r) // can be joined
            {
                len = 1;
                ele = l + 1;
            }
            else // cannot be joined, still reduce length
            {
                len = min(len, 2);
            }
        }
        else // reduce length
        {
            len = min(len, get<1>(L) + get<1>(R));
        }
    }

    return dp[i][j] = make_tuple(ele, len);
}

void cp()
{
    cin >> n;
    arr.resize(n);
    for(int &x : arr)
        cin >> x;

    cout << get<1>(solve(0, n - 1)) << endl;
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

