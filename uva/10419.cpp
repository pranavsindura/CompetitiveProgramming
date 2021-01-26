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
using pi = pair<string, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
vector<int> lim;

int dp[64][3][1005][16];

bool solve(int i, int cnt, int num, int left)
{
    if(i == sz(prime)) return num == 0 && left == 0;

    int &ret = dp[i][cnt][num][left];
    if(~ret) return ret;

    bool ans = false;

    if(cnt < lim[i] && num >= prime[i] && left > 0)
        ans |= solve(i, cnt + 1, num - prime[i], left - 1);
    ans |= solve(i + 1, 0, num, left);

    return ret = ans;
}

string path;
void trace(int i, int cnt, int num, int left)
{
    if(i == sz(prime)) return;

    if(cnt < lim[i] && num >= prime[i] && left > 0 && solve(i, cnt + 1, num - prime[i], left - 1))
    {
        path += to_string(prime[i]);
        path += '+';
        trace(i, cnt + 1, num - prime[i], left - 1);
    }
    else
        trace(i + 1, 0, num, left);
}

void cp()
{
    clr(dp, -1);
    sort(all(prime), [&](int a, int b)
    {
        return to_string(a) + "+" + to_string(b) < to_string(b) + "+" + to_string(a);
    });
    lim.assign(sz(prime), 2);
    for(int i = 0; i < sz(prime); i++)
        if(prime[i] == 2)
            lim[i] = 1;

    int n, k, test = 0;
    while(cin >> n >> k && n + k)
    {
        bool can = solve(0, 0, n, k);
        path = "No Solution.";
        if(can)
        {
            path.clear();
            trace(0, 0, n, k);
            path.pop_back();
        }
        cout << "CASE " << ++test << ":\n" << path << endl;
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

