#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

/*
	Fix one by one for [0, n-2) x [0, m-2)
	Fix two at a time for [n-2, n) x [0, m)
	Fix two at a time for [0, n) x [m-2, m)
	Fix four at a time for [n-2, n) x [m-2, m)

	Am i overcomplicating it?
*/

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;

    auto flip = [&](int i, int j)
    {
        arr[i][j] = char((arr[i][j] - '0') ^ 1 + 48);
    };

    vector<vector<int>> ops;
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            if(arr[i][j] == '1')
            {
                ops.pb({i, j, i + 1, j, i, j + 1});
                flip(i, j), flip(i, j + 1), flip(i + 1, j);
            }
        }
    }

    for(int j = 0; j < m - 2; j++)
    {
        int i = n - 2;
        int v = (arr[i + 1][j] - '0') * 2 + (arr[i][j] - '0');
        if(v == 0) continue;
        else if(v == 1)
        {
            ops.pb({i, j, i + 1, j + 1, i, j + 1});
            flip(i, j), flip(i + 1, j + 1), flip(i, j + 1);
        }
        else if(v == 2)
        {
            ops.pb({i + 1, j, i + 1, j + 1, i, j + 1});
            flip(i + 1, j), flip(i + 1, j + 1), flip(i, j + 1);
        }
        else
        {
            ops.pb({i + 1, j, i, j, i, j + 1});
            flip(i + 1, j), flip(i, j), flip(i, j + 1);
        }
    }

    for(int i = 0; i < n - 2; i++)
    {
        int j = m - 2;
        int v = (arr[i][j] - '0') * 2 + (arr[i][j + 1] - '0');
        if(v == 0) continue;
        else if(v == 1)
        {
            ops.pb({i, j + 1, i + 1, j + 1, i + 1, j});
            flip(i, j + 1), flip(i + 1, j + 1), flip(i + 1, j);
        }
        else if(v == 2)
        {
            ops.pb({i, j, i + 1, j + 1, i + 1, j});
            flip(i, j), flip(i + 1, j + 1), flip(i + 1, j);
        }
        else
        {
            ops.pb({i, j, i, j + 1, i + 1, j + 1});
            flip(i, j), flip(i, j + 1), flip(i + 1, j + 1);
        }
    }

    // too many cases, just brute force
    // should be done within 4 move
    bool found = false;
    function<void(int, vector<vector<int>>, vector<vector<int>>)> solve = [&](int d, vector<vector<int>> board, vector<vector<int>> moves)
    {
        if(found)
            return;
        if(d >= 4)
        {
            int sum = board[0][0] + board[0][1] + board[1][0] + board[1][1];
            if(sum == 0)
            {
                found = true;
                for(auto v : moves)
                    ops.pb(v), flip(v[0], v[1]), flip(v[2], v[3]), flip(v[4], v[5]);
            }
            return;
        }
        // do nothing
        solve(d + 1, board, moves);

        // top left
        moves.pb({n - 2, m - 2, n - 1, m - 2, n - 2, m - 1});
        board[0][0] ^= 1, board[0][1] ^= 1, board[1][0] ^= 1;
        solve(d + 1, board, moves);
        board[0][0] ^= 1, board[0][1] ^= 1, board[1][0] ^= 1;
        moves.pop_back();

        // bottom left
        moves.pb({n - 1, m - 2, n - 2, m - 2, n - 1, m - 1});
        board[1][0] ^= 1, board[0][0] ^= 1, board[1][1] ^= 1;
        solve(d + 1, board, moves);
        board[1][0] ^= 1, board[0][0] ^= 1, board[1][1] ^= 1;
        moves.pop_back();

        // bottom right
        moves.pb({n - 1, m - 1, n - 1, m - 2, n - 2, m - 1});
        board[1][1] ^= 1, board[1][0] ^= 1, board[0][1] ^= 1;
        solve(d + 1, board, moves);
        board[1][1] ^= 1, board[1][0] ^= 1, board[0][1] ^= 1;
        moves.pop_back();

        // top right
        moves.pb({n - 2, m - 1, n - 1, m - 1, n - 2, m - 2});
        board[0][1] ^= 1, board[1][1] ^= 1, board[0][0] ^= 1;
        solve(d + 1, board, moves);
        board[0][1] ^= 1, board[1][1] ^= 1, board[0][0] ^= 1;
        moves.pop_back();
    };

    vector<vector<int>> board = {{arr[n - 2][m - 2] - '0', arr[n - 2][m - 1] - '0'}, {arr[n - 1][m - 2] - '0', arr[n - 1][m - 1] - '0'}}, moves;
    solve(0, board, moves);

    cout << sz(ops) << endl;
    for(auto v : ops)
    {
        for(int x : v)
            cout << x + 1 << " ";
        cout << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}