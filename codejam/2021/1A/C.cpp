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
    int n, q;
    cin >> n >> q;
    vector<string> ans(n);
    vector<int> score(n);
    for(int i = 0; i < n; i++)
        cin >> ans[i] >> score[i];
    
    for(string &x : ans)
        for(char &y : x)
            if(y == 'T') y = '1';
            else y = '0';

    int valid = 0;
    int best_mask = -1;
    int best_score = -1;

    for(int my = 0; my < 1 << q; my++)
    {
        int expected = 0;
        valid = 0;
        for(int mask = 0; mask < 1 << q; mask++)
        {
            bool ok = true;
            for(int i = 0; i < n; i++)
            {
                int s = 0;
                for(int j = 0; j < q; j++)
                    s += (ans[i][j] - '0') == ((mask >> j) & 1);
                ok &= score[i] == s;
            }
            if(!ok) continue;
            valid++;
            int s = 0;
            for(int j = 0; j < q; j++)
                s += ((my >> j) & 1) == ((mask >> j) & 1);
            expected += s;
        }
        if(expected > best_score)
            best_score = expected, best_mask = my;
    }

    string best;
    for(int i = 0; i < q; i++)
        best += ((best_mask >> i) & 1) ? 'T' : 'F';
    int g = __gcd(best_score, valid);
    cout << best << " " << best_score / g << "/" << valid / g << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
