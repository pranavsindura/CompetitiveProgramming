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

map<pair<vector<string>, int>, pi> vis;

bool full(vector<string> &board)
{
    bool ok = false;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ok |= board[i][j] == '.';
    return !ok;
}

bool won(vector<string> &board)
{
    bool win = false;
    // same row
    for(int i = 0; i < 4; i++)
    {
        bool row = board[i][0] != '.';
        for(int j = 0; j < 4; j++ )
            row &= board[i][j] == board[i][0];
        win |= row;
    }
    // same col
    for(int j = 0; j < 4; j++)
    {
        bool col = board[0][j] != '.';
        for(int i = 0; i < 4; i++ )
            col &= board[i][j] == board[0][j];
        win |= col;
    }
    // diag 1
    bool d1 = board[0][0] != '.';
    for(int i = 0; i < 4; i++)
        d1 &= board[i][i] == board[0][0];
    win |= d1;
    // diag 2
    bool d2 = board[0][3] != '.';
    for(int i = 0; i < 4; i++)
        d2 &= board[i][3 - i] == board[0][3];
    win |= d2;
    return win;
}

pi solve(vector<string> &board, int player)
{
    if(vis.count({board, player})) return vis[ {board, player}];

    if(full(board) || won(board)) return vis[{board, player}] = {-1, -1};

    char op = player ? 'o' : 'x';
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] != '.') continue;

            board[i][j] = op;
            pi move = solve(board, player ^ 1);

            if(move.ff == -1)
            {
                board[i][j] = '.';
                return vis[ {board, player}] = {i, j};
            }

            board[i][j] = '.';
        }
    }
    return vis[ {board, player}] = {-1, -1};
}

void cp()
{
    string S;
    while(cin >> S && S[0] != '$')
    {
        vector<string> board(4);
        cin >> board[0] >> board[1] >> board[2] >> board[3];
        pi best = solve(board, 0);
        if(~best.ff)
            cout << "(" << best.ff << "," << best.ss << ")" << endl;
        else
            cout << "#####" << endl;
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

