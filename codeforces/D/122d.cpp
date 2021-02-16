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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> grp;
    for(int i = 0; i < n;)
    {
        int j = i;
        while(j + 1 < n && s[j + 1] == s[i]) j++;
        grp.push_back({s[i], i + 1, j + 1});
        i = j + 1;
    }

    for(int i = 0; i < sz(grp) - 1 && k > 0; i++)
    {
        auto &A = grp[i], &B = grp[i + 1];
        if(A[0] != '4' || B[0] != '7') continue;

        int x = A[2];
        if(x & 1) A[2]++, B[1]++;
        else A[2]--, B[1]--;
        k--;

        if(A[2] - A[1] + 1 <= 0 || B[2] - B[1] + 1 <= 0 || k == 0) continue;

        x = A[2];
        if(x & 1) A[2]++, B[1]++;
        else A[2]--, B[1]--;
        k--;

        if(A[2] - A[1] + 1 <= 0 || B[2] - B[1] + 1 <= 0 || k == 0) continue;

        k %= 2;
        i--;
    }

    string ans;
    for(int i = 0; i < sz(grp); i++)
        ans += string(grp[i][2] - grp[i][1] + 1, (char)grp[i][0]);
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
