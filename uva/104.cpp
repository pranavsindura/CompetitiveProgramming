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
double rate[25][25];
double dp[25][25][25];
double solve(int u, int d, int S)
{
    if(d == 0) return rate[u][S];

    double &ret = dp[u][d][S];
    if(fabs(ret + 1) > eps) return ret;

    double ans = rate[u][S];
    for(int i = 0; i < n; i++)
        ans = max(ans, rate[u][i] * solve(i, d - 1, S));
    return ret = ans;
}

vector<int> path;
void trace(int u, int d, int S)
{
    if(d == 0)
    {
        path.push_back(S);
        return;
    }

    double ans = solve(u, d, S);
    for(int i = 0; i < n; i++)
    {
        double me = rate[u][i] * solve(i, d - 1, S);
        if(fabs(ans - me) < eps)
        {
            path.push_back(i);
            trace(i, d - 1, S);
            return;
        }
    }
}

void cp()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                rate[i][j] = 1;
            else
                cin >> rate[i][j];

    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < n; j++)
    //         cout << rate[i][j] << " \n"[j == n - 1];

    clr(dp, -1);
    for(int LIM = 1; LIM <= n; LIM++)
    {
        for(int i = 0; i < n; i++)
        {
            double best = solve(i, LIM, i);
            if(best - 1 > 0.01)
            {
                path.clear();
                trace(i, LIM, i);
                cout << i + 1;
                for(int x : path)
                    cout << " " << x + 1;
                cout << endl;
                return;
            }
        }
    }

    cout << "no arbitrage sequence exists\n";
}

int main()
{
    FASTIO;
    while(cin >> n)
    {
        cp();
    }
    return 0;
}

