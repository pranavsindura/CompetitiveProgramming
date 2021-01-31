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

vector<string> tile(14);
bool is_triple(string &A, string &B, string &C)
{
    if(A == B && B == C) return true;
    if(A[1] == B[1] && B[1] == C[1] && B[0] - A[0] == 1 && C[0] - B[0] == 1) return true;
    return false;
}

#define set(mask, pos) (((mask) >> pos) & 1)

int dp[1 << 14][5];

bool check(int mask, int cnt)
{
    if(cnt >= 4) return true;
    if(__builtin_popcount(mask) < 3) return false;
    int &ret = dp[mask][cnt];
    if(~ret) return ret;
    ret = false;
    for(int i = 0; i < 14; i++)
        for(int j = 0; j < 14; j++)
            for(int k = 0; k < 14; k++)
                if(i != j && j != k && k != i
                        && set(mask, i) && set(mask, j) && set(mask, k)
                        && is_triple(tile[i], tile[j], tile[k]))
                    ret |= check(mask ^ (1 << i) ^ (1 << j) ^ (1 << k), cnt + 1);
    return ret;
}

void cp()
{
    for(string &x : tile)
        cin >> x;

    clr(dp, -1);
    bool win = false, ready = false;

    for(int i = 0; i < 14 && !win; i++)
        for(int j = i + 1; j < 14 && !win; j++)
            if(tile[i] == tile[j])
                win |= check(((1 << 14) - 1) ^ (1 << i) ^ (1 << j), 0);

    for(int k = 0; k < 14 && !ready && !win; k++)
    {
        string save = tile[k];
        for(int a = 1; a <= 9 && !ready && !win; a++)
            for(char b = 'a'; b <= 'c' && !ready && !win; b++)
            {
                tile[k] = to_string(a) + b;
                clr(dp, -1);

                for(int i = 0; i < 14 && !ready && !win; i++)
                    for(int j = i + 1; j < 14 && !ready && !win; j++)
                        if(tile[i] == tile[j])
                            ready |= check(((1 << 14) - 1) ^ (1 << i) ^ (1 << j), 0);
            }
        tile[k] = save;
    }

    if(win) cout << "Tsumo\n";
    else if(ready) cout << "Tenpai\n";
    else cout << "Noten\n";
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

