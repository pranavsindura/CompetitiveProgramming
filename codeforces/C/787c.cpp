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
const int MAXN = 7e3 + 5;

int N;
vector<vector<int>> moves;
int stat[2][MAXN];
int cnt[2][MAXN];
bool vis[2][MAXN];

void dfs(int pos, int turn)
{
    for(int x : moves[turn ^ 1])
    {
        int npos = (pos - x + N) % N;

        if(stat[turn ^ 1][npos]) continue;

        if(stat[turn][pos] == -1) // i am lost state
        {
            stat[turn ^ 1][npos] = 1;
            dfs(npos, turn ^ 1);
        }
        else // i am winning state
        {
            cnt[turn ^ 1][npos]--;
            if(cnt[turn ^ 1][npos] == 0) // no more wins, turns to a losing state
            {
                stat[turn ^ 1][npos] = -1;
                dfs(npos, turn ^ 1);
            }
        }
    }
}

void cp()
{
    int K1, K2;
    cin >> N;
    moves.assign(2, vector<int>());
    cin >> K1;
    moves[0].resize(K1);
    for(int &x : moves[0])
        cin >> x;
    cin >> K2;
    moves[1].resize(K2);
    for(int &x : moves[1])
        cin >> x;

    fill(cnt[0] + 1, cnt[0] + N, K1);
    fill(cnt[1] + 1, cnt[1] + N, K2);

    cnt[0][0] = 0;
    cnt[1][0] = 0;
    stat[0][0] = -1;
    stat[1][0] = -1;

    dfs(0, 0);
    dfs(0, 1);

    for(int i = 1; i < N; i++)
    {
        if(stat[0][i] == 1)
            cout << "Win ";
        else if(stat[0][i] == -1)
            cout << "Lose ";
        else
            cout << "Loop ";
    }
    cout << endl;

    for(int i = 1; i < N; i++)
    {
        if(stat[1][i] == 1)
            cout << "Win ";
        else if(stat[1][i] == -1)
            cout << "Lose ";
        else
            cout << "Loop ";
    }
    cout << endl;

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

