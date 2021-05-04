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

char grid[4][4];
bool vis[1 << 26];
bool valid(int x, int y)
{
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bitset<6> up(bitset<6> _dice)
{
    string dice = _dice.to_string();
    reverse(all(dice));
    // 0->1->5->3->0
    int f0 = dice[0];
    swap(dice[0], dice[3]);
    swap(dice[3], dice[5]);
    swap(dice[5], dice[1]);
    dice[1] = f0;
    reverse(all(dice));
    return bitset<6>(dice);
}

bitset<6> down(bitset<6> _dice)
{
    string dice = _dice.to_string();
    reverse(all(dice));
    // 0->3->5->1->0
    int f0 = dice[0];
    swap(dice[0], dice[1]);
    swap(dice[1], dice[5]);
    swap(dice[5], dice[3]);
    dice[3] = f0;
    reverse(all(dice));
    return bitset<6>(dice);
}

bitset<6> right(bitset<6> _dice)
{
    string dice = _dice.to_string();
    reverse(all(dice));
    // 0->2->5->4->0
    int f0 = dice[0];
    swap(dice[0], dice[4]);
    swap(dice[4], dice[5]);
    swap(dice[5], dice[2]);
    dice[2] = f0;
    reverse(all(dice));
    return bitset<6>(dice);
}

bitset<6> left(bitset<6> _dice)
{
    string dice = _dice.to_string();
    reverse(all(dice));
    // 0->4->5->2->0
    int f0 = dice[0];
    swap(dice[0], dice[2]);
    swap(dice[2], dice[5]);
    swap(dice[5], dice[4]);
    dice[4] = f0;
    reverse(all(dice));
    return bitset<6>(dice);
}

int get(bitset<16> board, int x, int y, bitset<6> dice)
{
    return (board.to_ulong() << 10) | (x << 8) | (y << 6) | dice.to_ulong();
}

int solve(int S)
{
    queue<pi> q;
    q.push({S, 0});
    while(!q.empty())
    {
        int mask = q.front().ff;
        int D = q.front().ss;
        q.pop();

        vis[mask] = 1;

        bitset<6> dice(mask & 63);
        mask >>= 6;
        int y = mask & 3;
        mask >>= 2;
        int x = mask & 3;
        mask >>= 2;
        bitset<16> board(mask & 65535);
        mask >>= 16;

        if(dice.to_ulong() + 1 == (1 << 6)) return D;

        // go up
        if(valid(x - 1, y))
        {
            bitset<16> nboard = board;
            bitset<6> ndice = dice;
            // face 3 touches
            if(ndice[3] && !nboard[(x - 1) * 4 + y])
                nboard[(x - 1) * 4 + y] = 1, ndice[3] = 0;
            else if(!ndice[3] && nboard[(x - 1) * 4 + y])
                nboard[(x - 1) * 4 + y] = 0, ndice[3] = 1;
            ndice = up(ndice);
            int nmask = get(nboard, x - 1, y, ndice);
            if(!vis[nmask])
                q.push({nmask, D + 1});
            vis[nmask] = 1;
        }
        // go down
        if(valid(x + 1, y))
        {
            bitset<16> nboard = board;
            bitset<6> ndice = dice;
            // face 1 touches
            if(ndice[1] && !nboard[(x + 1) * 4 + y])
                nboard[(x + 1) * 4 + y] = 1, ndice[1] = 0;
            else if(!ndice[1] && nboard[(x + 1) * 4 + y])
                nboard[(x + 1) * 4 + y] = 0, ndice[1] = 1;
            ndice = down(ndice);
            int nmask = get(nboard, x + 1, y, ndice);
            if(!vis[nmask])
                q.push({nmask, D + 1});
            vis[nmask] = 1;
        }
        // go right
        if(valid(x, y + 1))
        {
            bitset<16> nboard = board;
            bitset<6> ndice = dice;
            // face 4 touches
            if(ndice[4] && !nboard[x * 4 + y + 1])
                nboard[x * 4 + y + 1] = 1, ndice[4] = 0;
            else if(!ndice[4] && nboard[x * 4 + y + 1])
                nboard[x * 4 + y + 1] = 0, ndice[4] = 1;
            ndice = right(ndice);
            int nmask = get(nboard, x, y + 1, ndice);
            if(!vis[nmask])
                q.push({nmask, D + 1});
            vis[nmask] = 1;
        }
        // go left
        if(valid(x, y - 1))
        {
            bitset<16> nboard = board;
            bitset<6> ndice = dice;
            // face 2 touches
            if(ndice[2] && !nboard[x * 4 + y - 1])
                nboard[x * 4 + y - 1] = 1, ndice[2] = 0;
            else if(!ndice[2] && nboard[x * 4 + y - 1])
                nboard[x * 4 + y - 1] = 0, ndice[2] = 1;
            ndice = left(ndice);
            int nmask = get(nboard, x, y - 1, ndice);
            if(!vis[nmask])
                q.push({nmask, D + 1});
            vis[nmask] = 1;
        }
    }
    return inf;
}

void cp()
{
    for(int i = 0; i < 4; i++)
        cin >> grid[i];

    bitset<16> board(0);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i * 4 + j] = grid[i][j] == 'X';
    int x, y;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(grid[i][j] == 'D')
                x = i, y = j;
    bitset<6> dice(0);

    int mask = get(board, x, y, dice);

    clr(vis, 0);
    int ans = solve(mask);
    if(ans == inf) cout << "impossible\n";
    else cout << ans << endl;
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
