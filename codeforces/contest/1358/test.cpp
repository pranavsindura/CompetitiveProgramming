#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(pii a)
{
    int i = a.ff, j = a.ss;
    return (i >= 1 && i <= 6 && j >= 1 && j <= 6);
}
set<int> s;

int val[7][7] =
{
    0, 1, 2, 4, 7, 11, 16,
    0, 3, 5, 8, 12, 17, 0,
    0, 6, 9, 13, 18, 0, 0,
    0, 10, 14, 19, 0, 0, 0,
    0, 15, 20, 0, 0, 0, 0,
    0, 21, 0, 0, 0, 0, 0
};

void dfs(pii st, pii en, int sum)
{
    if(st == en)
    {
        s.insert(sum);
    }
    else
    {
        pii down = st;
        down.ff++;
        pii right = st;
        right.ss++;
        if(valid(down))
            dfs(down, en, sum + val[down.ff][down.ss]);
        if(valid(right))
            dfs(right, en, sum + val[down.ff][down.ss]);
    }
}

void cp()
{
    pii st, en;
    // cin >> st.ff >> st.ss >> en.ff >> en.ss;
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            s.clear();
            dfs({1, 1}, {i, j}, val[1][1]);
            cout << sz(s) << " ";
        }
        cout << endl;
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