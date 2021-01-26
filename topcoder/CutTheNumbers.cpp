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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

class CutTheNumbers
{
public:
    int ops;
    map<vector<string>, int> dp;
    CutTheNumbers()
    {
        ops = 0;
    }
    int maximumSum(vector <string> board)
    {
        int ans = 0;
        int n = sz(board), m = sz(board[0]);
        // cout << ops << endl;
        if(board == vector<string>(n, string(m, '#')))
            return 0;

        if(dp.count(board))
            return dp[board];

        // pick a row
        for(int i = 0; i < n; i++)
        {
            bool foundhash = false;
            for(int j = 0; j < m && !foundhash; j++)
            {
                for(int k = j; k < m && !foundhash; k++)
                {
                    //check no #, save string and make num
                    bool can_use = true;
                    int num = 0;
                    string save;
                    for(int l = j; l <= k; l++, ops++)
                        if(board[i][l] == '#')
                            can_use = false, save += board[i][l], foundhash = true;
                        else
                            save += board[i][l], num =  num * 10 + (board[i][l] - '0'), board[i][l] = '#';
                    if(can_use)
                        ans = max(ans, num + maximumSum(board));
                    // undo #
                    for(int l = j; l <= k; l++)
                        board[i][l] = save[l - j];
                }
            }
        }

        //pick a col
        for(int i = 0; i < m; i++)
        {
            bool foundhash = false;
            for(int j = 0; j < n && !foundhash; j++)
            {
                for(int k = j; k < n && !foundhash; k++)
                {
                    //check no #, save string and make num
                    bool can_use = true;
                    int num = 0;
                    string save;
                    for(int l = j; l <= k; l++, ops++)
                        if(board[l][i] == '#')
                            can_use = false, save += board[l][i], foundhash = true;
                        else
                            save += board[l][i], num =  num * 10 + (board[l][i] - '0'), board[l][i] = '#';
                    if(can_use)
                        ans = max(ans, num + maximumSum(board));
                    // undo #
                    for(int l = j; l <= k; l++)
                        board[l][i] = save[l - j];
                }
            }
        }

        return dp[board] = ans;
    }
};
// int main()
// {
//     vector<string> inp = {"9999", "9999", "9999", "9999"};
//     CutTheNumbers c;
//     cout << c.maximumSum(inp) << endl;
//     cout << c.ops << endl;
//     cout << sz(c.dp) << endl;
//     return 0;
// }