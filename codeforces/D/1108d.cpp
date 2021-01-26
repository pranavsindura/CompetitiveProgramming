#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e5 + 5;

// GREEDY

void cp()
{
    int n;
    string s;
    cin >> n >> s;
    int ops = 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
        {
            for(char x : {'R', 'G', 'B'})
            {
                if(s[i - 1] != x && (i == n - 1 || s[i + 1] != x))
                {
                    s[i] = x;
                    ops++;
                    break;
                }
            }
        }
    }

    cout << ops << endl;
    cout << s << endl;
}

// DP + Tracing

// int n;
// string s, res;

// int dp[MAXN][4];

// int get(char x)
// {
//     if(x == 'R')
//         return 0;
//     else if(x == 'G')
//         return 1;
//     else if(x == 'B')
//         return 2;
//     else
//         return 3;
// }

// char rev_get(int x)
// {
//     if(x == 0)
//         return 'R';
//     else if(x == 1)
//         return 'G';
//     else if(x == 2)
//         return 'B';
// }

// int solve(int i, int prev)
// {
//     if(i == n)
//         return 0;

//     int &ret = dp[i][prev];
//     if(~ret)
//         return ret;

//     int ans = 1e6;
//     for(int j = 0; j < 3; j++)
//         if(j != prev)
//             ans = min(ans, (j != get(s[i])) + solve(i + 1, j));
//     return ret = ans;
// }

// void trace(int i, int prev)
// {
//     if(i == n)
//         return;

//     int ans = solve(i, prev);
//     for(int j = 0; j < 3; j++)
//     {
//         if(j != prev)
//         {
//             if((j != get(s[i])) + solve(i + 1, j) == ans)
//             {
//                 res += rev_get(j);
//                 trace(i + 1, j);
//                 return;
//             }
//         }
//     }
// }

// void cp()
// {
//     cin >> n >> s;
//     clr(dp, -1);
//     int op = solve(0, 3);
//     cout << op << endl;
//     trace(0, 3);
//     cout << res << endl;
// }

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